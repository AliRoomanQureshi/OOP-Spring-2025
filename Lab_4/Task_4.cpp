#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    float rentalPrice;
    bool available;
    float totalRevenue;

public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        rentalPrice = 0.0;
        available = true;
        totalRevenue = 0.0;
    }

    Car(string b, string m, float rP, bool avail) {
        brand = b;
        model = m;
        rentalPrice = rP;
        available = avail;
        totalRevenue = 0.0;
    }

    Car(const Car &c) {
        brand = c.brand;
        model = c.model;
        rentalPrice = c.rentalPrice;
        available = c.available;
        totalRevenue = c.totalRevenue;
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
            cout<<"Car is successfully rented. You got a 10% discount for renting for more than 10 days.\n";
            cout<<"Final price: Rs "<<rentalPrice<<"\n";
        } 
        else if (days > 5) {
            available = false;
            rentalPrice = rentalPrice - (0.05 * rentalPrice);
            cout<<"Car is successfully rented. You got a 5% discount for renting for more than 5 days.\n";
            cout<<"Final price: Rs "<<rentalPrice<<"\n";
        } 
        else {
            available = false;
            cout<<"Car is successfully rented.\n";
            cout<<"Final price: Rs "<<rentalPrice<<"\n";
        }

        this->totalRevenue += (this->rentalPrice*days);
    }

    void displayCar() {
        cout<<"Brand: "<<brand<<"\n";
        cout<<"Model: "<<model<<"\n";
        cout<<"Rental Price: Rs "<<rentalPrice<<"\n";
        cout<<"Availability: "<<(available ? "Available" : "Rented")<<"\n";
        cout<<"Total Revenue Generated: Rs "<<totalRevenue<<"\n";
    }
};

int main() {
    Car c1("Toyota", "Sedan", 1000.0, true);
    c1.displayCar();
    cout<<"\nProcessing a rental request for 7 days...\n";
    c1.rentalRequest(7);
    c1.displayCar();
    cout<<"\nProcessing another rental request for 12 days...\n";
    c1.updateDetail("Toyota", "Sedan", 1000.0, true);
    c1.rentalRequest(12);
    c1.displayCar();

    return 0;
}
