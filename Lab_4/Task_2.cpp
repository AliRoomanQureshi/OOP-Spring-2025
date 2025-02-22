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
            cout<<"Car is not available to rent.";;
            return;
        }

        if (days > 10) {
            available = false;
            rentalPrice = rentalPrice - (0.10 * rentalPrice);
            cout<<"Car is successfully rented. You got a 10% discount for renting for more than 10 days.";
            cout<<"Final price: Rs "<<rentalPrice;;
        } else if (days > 5 && days <= 10) {
            available = false;
            rentalPrice = rentalPrice - (0.05 * rentalPrice);
            cout<<"Car is successfully rented. You got a 5% discount for renting for more than 5 days.";
            cout<<"\nFinal price: Rs "<<rentalPrice;;
        } else {
            available = false;
            cout<<"\nCar is successfully rented.";
            cout<<"\nFinal price: Rs "<<rentalPrice;;
        }
    }

    void displayCar() {
        cout<<"\nBrand: "<<brand;
        cout<<"\nModel: "<<model;
        cout<<"\nRental Price: Rs "<<rentalPrice;
        cout<<"\nAvailability: "<<(available ? "Available" : "Rented")<<endl;
    }
};

int main() {
    Car c;
    c.updateDetail("Toyota", "Sedan", 12.5, true);
    c.displayCar();
    c.rentalRequest(7);
    c.displayCar();
    return 0;
}
