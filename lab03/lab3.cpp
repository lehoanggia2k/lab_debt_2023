#include <iostream>
#include <map>
#include <string>
#include <cmath> 

enum class DeliveryType { Turbo, Standard, Economy };

class Destination {
public:
    std::string name;
    int index;

    Destination(std::string _name, int _index) : name(_name), index(_index) {}
};

class DistanceMatrix {
public:
    static const int SIZE = 16;
    int matrix[SIZE][SIZE];

    DistanceMatrix() {
        // Initialize the distance matrix here 
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                matrix[i][j] = abs(i - j) * 100; 
            }
        }
    }

    void updateMatrix(DeliveryType type) {
        // Update matrix based on delivery type (Turbo, Standard, Economy)
        if (type == DeliveryType::Turbo) {
            // Update distances for Turbo delivery
        } else if (type == DeliveryType::Standard) {
            // Update distances for Standard delivery
        } else if (type == DeliveryType::Economy) {
            // Update distances for Economy delivery
        }
    }

    int getDistance(int startPoint, int endPoint) {
        return matrix[startPoint][endPoint];
    }
};

class Vehicle {
protected:
    int speed;
    int volume;
    double price;

public:
    Vehicle(int _speed, int _volume, double _price) : speed(_speed), volume(_volume), price(_price) {}

    virtual double calculateCost(int mass, int distance) = 0;
    virtual double calculateTime(int distance) = 0;
};

class Train : public Vehicle {
public:
    Train() : Vehicle(100, 500, 200) {}

    double calculateCost(int mass, int distance) override {
        // Calculate transportation cost by train
        return price * distance;
    }

    double calculateTime(int distance) override {
        // Calculate transportation time by train
        return static_cast<double>(distance) / speed;
    }
};

class Car : public Vehicle {
public:
    Car() : Vehicle(60, 50, 100) {}

    double calculateCost(int mass, int distance) override {
        // Calculate transportation cost by car
        return price * distance * (mass > 500 ? 1.5 : 1.0);
    }

    double calculateTime(int distance) override {
        // Calculate transportation time by car
        return static_cast<double>(distance) / speed;
    }
};

class Plane : public Vehicle {
public:
    Plane() : Vehicle(300, 100, 500) {}

    double calculateCost(int mass, int distance) override {
        // Calculate transportation cost by plane
        return price * distance;
    }

    double calculateTime(int distance) override {
        // Calculate transportation time by plane
        return static_cast<double>(distance) / speed;
    }
};

class Order {
private:
    Destination start;
    Destination end;
    DeliveryType deliveryType;
    Vehicle* vehicle;
    int volume;
    DistanceMatrix matrix;

public:
    Order(DeliveryType type, Destination _start, Destination _end, int _volume)
        : start(_start), end(_end), deliveryType(type), volume(_volume) {
        // Select and initialize the transport vehicle based on the type
        switch (type) {
        case DeliveryType::Turbo:
            vehicle = new Plane();
            break;
        case DeliveryType::Standard:
            vehicle = new Train();
            break;
        case DeliveryType::Economy:
            vehicle = new Car();
            break;
        }
    }

    ~Order() {
        delete vehicle;
    }

    double calculateTotalCost() {
        int distance = matrix.getDistance(start.index, end.index);
        return vehicle->calculateCost(volume, distance);
    }

    double calculateTotalTime() {
        int distance = matrix.getDistance(start.index, end.index);
        return vehicle->calculateTime(distance);
    }
};

int main() {
    // Create sample destinations
    Destination moscow("Moscow", 0);
    Destination nizhniyNovgorod("Nizhniy Novgorod", 7);

    // Create an order
    Order orderTub(DeliveryType::Turbo, moscow, nizhniyNovgorod, 200);
    Order orderEco(DeliveryType::Economy, moscow, nizhniyNovgorod, 200);
    Order orderSta(DeliveryType::Standard, moscow, nizhniyNovgorod, 200);

    // Calculate and display total cost and time
    std::cout << "Turbo " << std::endl;
    std::cout << "Total cost: " << orderTub.calculateTotalCost() << std::endl;
    std::cout << "Total time: " << orderTub.calculateTotalTime() << std::endl;
    std::cout << "Economy " << std::endl;
    std::cout << "Total cost: " << orderEco.calculateTotalCost() << std::endl;
    std::cout << "Total time: " << orderEco.calculateTotalTime() << std::endl;
    std::cout << "Standard " << std::endl;
    std::cout << "Total cost: " << orderSta.calculateTotalCost() << std::endl;
    std::cout << "Total time: " << orderSta.calculateTotalTime() << std::endl;
    return 0;
}
