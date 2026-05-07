class Vehicle {
public:
    virtual string getType() = 0;
};

class Car : public Vehicle {
public:
    string getType() override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    string getType() override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    string getType() override {
        return "Truck";
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
};

class CarFactory : public VehicleFactory {
    // Write your code here
private:
    Vehicle* car;
public:
    CarFactory()
    {
        car = nullptr;
    }
    Vehicle* createVehicle() override
    {
        if(nullptr == car)
        {
            car = new Car;
        }
        return car;
    }
    ~CarFactory()
    {
        delete car;
    }
};

class BikeFactory : public VehicleFactory {
    // Write your code here
    private:
    Vehicle* car;
public:
    BikeFactory()
    {
        car = nullptr;
    }
    Vehicle* createVehicle() override
    {
        if(nullptr == car)
        {
            car = new Bike;
        }
        return car;
    }
    ~BikeFactory()
    {
        delete car;
    }
};

class TruckFactory : public VehicleFactory {
    // Write your code here
    private:
    Vehicle* car;
public:
    TruckFactory()
    {
        car = nullptr;
    }
    Vehicle* createVehicle() override
    {
        if(nullptr == car)
        {
            car = new Truck;
        }
        return car;
    }
    ~TruckFactory()
    {
        delete car;
    }
};
