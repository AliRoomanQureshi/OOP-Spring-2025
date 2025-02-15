#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    float fuelCapacity;
    float currentFuelLevel;

public:
    Car(string b, string m, float capacity) {
        brand = b;
        model = m;
        fuelCapacity = capacity;
        currentFuelLevel = capacity;
    }

    void drive(float fuelUsed) {
        if (fuelUsed > 0 && fuelUsed <= currentFuelLevel) {
            currentFuelLevel -= fuelUsed;
            cout<<"Drove the car using "<<fuelUsed<<" liters of fuel.\n";
            if (currentFuelLevel < 5){
                cout<<"Warning! Fuel level is low.\n";
            }
        } else { 
            cout<<"Not enough fuel to drive!\n";
            }
    }

    void refuel(float fuelAmount) {
        if (fuelAmount > 0 && (currentFuelLevel + fuelAmount) <= fuelCapacity) {
            currentFuelLevel += fuelAmount;
            cout<<"Refueled "<<fuelAmount<<" liters. Current fuel: "<<currentFuelLevel<<" liters.\n";
        } else{
            cout<<"Invalid refuel amount! Tank capacity exceeded.\n";
            }
    }

    void checkFuelStatus() {
        cout<<"Current fuel level: "<<currentFuelLevel<<" liters.\n";
    }
};

int main() {
    Car myCar("Toyota", "Corolla", 50);
    myCar.checkFuelStatus();
    myCar.drive(15);
    myCar.checkFuelStatus();
    myCar.drive(37);
    myCar.checkFuelStatus();
    myCar.refuel(10);
    myCar.checkFuelStatus();
    return 0;
}
