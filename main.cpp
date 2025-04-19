#include <iostream>
#include <memory>
#include <string>


class Vehicle {
public:
    virtual void drive() const = 0;
    virtual std::string getType() const = 0;
    virtual ~Vehicle() = default;
};


class Car : public Vehicle {
public:
    void drive() const override {
        std::cout << "Driving a car!" << std::endl;
    }

    std::string getType() const override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    void drive() const override {
        std::cout << "Riding a bike!" << std::endl;
    }

    std::string getType() const override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    void drive() const override {
        std::cout << "Driving a truck!" << std::endl;
    }

    std::string getType() const override {
        return "Truck";
    }
};

class VehicleFactory {
public:
    enum class VehicleType { CAR, BIKE, TRUCK };

    static std::unique_ptr<Vehicle> createVehicle(VehicleType type) {
        switch (type) {
            case VehicleType::CAR:
                return std::make_unique<Car>();
            case VehicleType::BIKE:
                return std::make_unique<Bike>();
            case VehicleType::TRUCK:
                return std::make_unique<Truck>();
            default:
                return nullptr;
        }
    }
};
