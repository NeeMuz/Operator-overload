#include <iostream>
#include <locale>

class Airplane {
public:
    int passengers;
    int maxPassengers;

    Airplane(int maxPass) : passengers(0), maxPassengers(maxPass) {}

    bool operator==(const Airplane& other) const {
        return maxPassengers == other.maxPassengers;
    }

    Airplane& operator++() { return passengers < maxPassengers ? ++passengers, *this : *this; }
    Airplane& operator--() { return passengers > 0 ? --passengers, * this : *this; }

    bool operator>(const Airplane& other) const {
        return maxPassengers > other.maxPassengers;
    }
};

int main() {
    std::locale::global(std::locale(""));

    Airplane plane1(150), plane2(200);

    std::cout << "The airplanes have " << (plane1 == plane2 ? "the same" : "different") << " maximum passenger capacity." << std::endl;

    std::cout << "Airplane " << (plane1 > plane2 ? "1" : "2") << " has a higher maximum passenger capacity." << std::endl;

    auto printInfo = [](const Airplane& plane) {
        std::cout << "The airplane has " << plane.passengers << " passengers and can hold a maximum of "
            << plane.maxPassengers << " passengers." << std::endl;
        };

    ++plane1; --plane2;
    printInfo(plane1);
    printInfo(plane2);

    return 0;
}
