#include <iostream>
using namespace std;

class Engine {
private:
    int horsepower;
    string type;

public:
    Engine(int horsepower, const string& type)
        : horsepower(horsepower), type(type) {}

    void displayInfo() const {
        cout << "Engine: " << horsepower << "Type: " << type << endl;
    }
};

class Driver {
private:
    string name;
    int age;

public:
    Driver(const string& name, int age)
        : name(name), age(age) {}

    void displayInfo() const {
        cout << "Driver: " << name << "Age: " << age << " years" << endl;
    }
};

class Car {
private:
    string brand;
    string model;
    int year;
    Engine engine;
    Driver* driver;

public:
    Car(const string& brand, const string& model, int year, const Engine& engine)
        : brand(brand), model(model), year(year), engine(engine), driver(nullptr) {}

    void assignDriver(Driver* driver) {
        this->driver = driver;
    }

    void displayInfo() const {
        cout << "Car: " << brand << " " << model << " Year of release: " << year << endl;
        engine.displayInfo();
        if (driver) {
            driver->displayInfo();
        }
        else {
            cout << "Driver: absent" << endl;
        }
    }
};

int main() {
    Engine engine1(150, "Gasoline");
    Engine engine2(200, "Diesel");

    Car car1("Toyota", "Corolla", 2020, engine1);
    Car car2("BMW", "X5", 2022, engine2);

    Driver driver1("ivan", 35);
    Driver driver2("oleksander", 40);

    car1.assignDriver(&driver1);
    car2.assignDriver(&driver2);

    car1.displayInfo();
    cout << endl;
    car2.displayInfo();
}
