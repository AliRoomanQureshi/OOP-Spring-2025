#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor {
private:
    float temperature;
public:
    void readData() override {
        temperature = 24.7;
    }

    void displayReport() override {
        cout << "Thermometer Report:\n";
        cout << "Temperature: " << temperature << "°C\n\n";
    }
};

class Barometer : public WeatherSensor {
private:
    float pressure;
public:
    void readData() override {
        pressure = 1012.8;
    }

    void displayReport() override {
        cout << "Barometer Report:\n";
        cout << "Pressure: " << pressure << " hPa\n\n";
    }
};

int main() {
    WeatherSensor* sensors[2];

    sensors[0] = new Thermometer();
    sensors[1] = new Barometer();

    for (int i = 0; i < 2; ++i) {
        sensors[i]->readData();
        sensors[i]->displayReport();
    }

    for (int i = 0; i < 2; ++i) {
        delete sensors[i];
    }

    return 0;
}
