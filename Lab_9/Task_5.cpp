#include <iostream>
#include <string>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;
public:
    Shipment(string tn, double w) : trackingNumber(tn), weight(w) {}
    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
    virtual ~Shipment() {}
};

class AirFreight : public Shipment {
public:
    AirFreight(string tn, double w) : Shipment(tn, w) {}
    void estimateDeliveryTime() override {
        cout << "Estimated Delivery Time (Air): " << weight * 0.5 << " hours\n";
    }
    void showDetails() override {
        cout << "Air Freight\nTracking Number: " << trackingNumber << "\nWeight: " << weight << " kg\n";
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string tn, double w) : Shipment(tn, w) {}
    void estimateDeliveryTime() override {
        cout << "Estimated Delivery Time (Ground): " << weight * 2.0 << " hours\n";
    }
    void showDetails() override {
        cout << "Ground Shipment\nTracking Number: " << trackingNumber << "\nWeight: " << weight << " kg\n";
    }
};

int main() {
    Shipment* shipments[2];

    shipments[0] = new AirFreight("AIR123", 10.5);
    shipments[1] = new GroundShipment("GRD456", 10.5);

    for (int i = 0; i < 2; ++i) {
        shipments[i]->showDetails();
        shipments[i]->estimateDeliveryTime();
        cout << endl;
    }

    for (int i = 0; i < 2; ++i) {
        delete shipments[i];
    }
    return 0;
}
