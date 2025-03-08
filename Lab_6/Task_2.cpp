#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;

public:
    Vehicle(string b, int s) {
        brand = b;
        speed = s;
    }

    virtual void displayDetails() {
        cout<<"Brand: "<<brand<<endl;
        cout<<"Speed: "<<speed<<" km/h"<<endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
protected:
    int seats;

public:
    Car(string b, int s, int seatCount) : Vehicle(b, s) {
        seats = seatCount;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout<<"Seats: "<<seats<<endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;

public:
    ElectricCar(string b, int s, int seatCount, int battery) : Car(b, s, seatCount) {
        batteryLife = battery;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout<<"Seats: "<<seats<<endl;
        cout<<"Battery Life: "<<batteryLife<<" hours"<<endl;
    }
};

int main() {
    string brand;
    int speed, seats, batteryLife;

    cout<<"Enter car brand: ";
    getline(cin, brand);
    cout<<"Enter car speed (km/h): ";
    cin>>speed;
    cout<<"Enter number of seats: ";
    cin>>seats;
    cout<<"Enter battery life (hours): ";
    cin>>batteryLife;

    ElectricCar eCar(brand, speed, seats, batteryLife);
    cout<<"\nElectric Car Details:\n";
    eCar.displayDetails();

    return 0;
}
