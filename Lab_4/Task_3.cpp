#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    float rentalPrice;
    bool available;

public:
        Car() {
        brand = "Unknown";
        model = "Generic";
        rentalPrice = 0.0;
        available = true;
    }

    Car(string b, string m, float rP, bool avail) {
        brand = b;
        model = m;
        rentalPrice = rP;
        available = avail;
    }

    Car(const Car &c) {
        brand = c.brand;
        model = c.model;
        rentalPrice = c.rentalPrice;
        available = c.available;
        cout<<"Copy constructor called. Car copied successfully.\n";
    }

    ~Car() {
        cout<<"Car object with model "<<model<<" is being removed from memory.\n";
    }

    void updateDetail(string newBrand, string newModel, float nrP, bool avail) {
        brand = newBrand;
        model = newModel;
        rentalPrice = nrP;
        available = avail;
    }

    bool availability() {
        return available;
    }

    void rentalRequest(int days) {
        if (!available) {
            cout<<"Car is not available to rent.\n";
            return;
        }

        if (days > 10) {
            available = false;
            rentalPrice = rentalPrice - (0.10 * rentalPrice);
            cout<<"Car is successfully rented. You got a 10% discount for renting for more than 10 days.\nFinal price: Rs "<<rentalPrice<<"\n";
        } else if (days > 5) {
            available = false;
            rentalPrice = rentalPrice - (0.05 * rentalPrice);
            cout<<"Car is successfully rented. You got a 5% discount for renting for more than 5 days.\nFinal price: Rs "<<rentalPrice<<"\n";
        } else {
            available = false;
            cout<<"Car is successfully rented.\nFinal price: Rs "<<rentalPrice<<"\n";
        }
    }

    void displayCar() {
        cout<<"Brand: "<<brand<<"\n";
        cout<<"Model: "<< model<<"\n";
        cout<<"Rental Price: Rs "<<rentalPrice<<"\n";
        cout<<"Availability: "<<(available ? "Available":"Rented")<<"\n";
    }
};

int main() {
     Car c1("Toyota", "Sedan", 12.5, true);
    c1.displayCar();

    cout<<"\nCreating a copy of the car using the copy constructor...\n";
    Car c2 = c1;
    c2.displayCar();

    cout<<"\nModifying the original car...\n";
    c1.updateDetail("Honda", "Civic", 15.0, false);
    cout<<"After modifying the original car:\n";
    c1.displayCar();

    cout<<"\nVerifying that the copied car remains unchanged:\n";
    c2.displayCar();

    return 0;
}
