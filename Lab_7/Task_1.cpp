#include <iostream>
#include <string>

using namespace std;

class Device {
    protected:
        int deviceID;
        string deviceName;
        bool status;
        string location;

    public:
        Device(int id, const string& name, bool stat, const string& loc = "")
            : deviceID(id), deviceName(name), status(stat), location(loc) {}

        virtual void turnOn() {
            status = true;
        }

        virtual void turnOff() {
            status = false;
        }

        virtual void getStatus() {
            cout<<"Device Name:"<<deviceName<<", Status:"<<(status ? "ON" : "OFF")<<endl;
        }

        virtual void displayInfo() {
            cout<<"Device ID:"<<deviceID<<", Name:"<<deviceName<<", Status:"<<(status ? "ON" : "OFF")<<", Location:"<<location<<endl;
        }

        virtual ~Device() {}
};

class Light : public Device {
    int brightnessLevel;
    string colorMode;

    public:
        Light(int id, const string& name, bool stat, const string& loc, int brightness, const string& mode) 
            : Device(id, name, stat, loc), brightnessLevel(brightness), colorMode(mode) {}

        void displayInfo() override {
            Device::displayInfo();
            cout<<"Brightness Level:"<<brightnessLevel<<", Color Mode:"<<colorMode<<endl;
        }
};

class Thermostat : public Device {
    float temperature;
    string mode;
    float targetTemperature;

    public:
        Thermostat(int id, const string& name, bool stat, const string& loc, float temp, const string& m, float targetTemp)
            : Device(id, name, stat, loc), temperature(temp), mode(m), targetTemperature(targetTemp) {}

        void getStatus() override {
            cout<<"Device Name:"<<deviceName<<", Status:"<<(status ? "ON" : "OFF")<<", Current Temperature:"<<temperature<<", Mode:"<<mode<<", Target Temperature:"<<targetTemperature<<endl;
        }
};

class SecurityCamera : public Device {
    int resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

    public:
        SecurityCamera(int id, const string& name, bool stat, const string& loc, int res, bool nightVision)
            : Device(id, name, stat, loc), resolution(res), nightVisionEnabled(nightVision), recordingStatus(false) {}

        void turnOn() override {
            Device::turnOn();
            recordingStatus = true;
            cout<<"Device Name:"<<deviceName<<" started recording."<<endl;
        }

        void displayInfo() override {
            Device::displayInfo();
            cout<<"Resolution:"<<resolution<<"p, Night Vision:"<<(nightVisionEnabled ? "Enabled" : "Disabled")<<", Recording:"<<(recordingStatus ? "Active" : "Inactive")<<endl;
        }
};

class SmartPlug : public Device {
    float powerConsumption;
    int timerSetting;

    public:
        SmartPlug(int id, const string& name, bool stat, const string& loc, float power, int timer)
            : Device(id, name, stat, loc), powerConsumption(power), timerSetting(timer) {}

        void turnOff() override {
            Device::turnOff();
            cout<<"Device Name:"<<deviceName<<" turned off. Power usage logged:"<<powerConsumption<<" kWh."<<endl;
        }

        void displayInfo() override {
            Device::displayInfo();
            cout<<"Power Consumption:"<<powerConsumption<<" kWh, Timer Setting:"<<timerSetting<<" mins"<<endl;
        }
};

int main() {
    Light light1(101, "Living Room Light", false, "Living Room", 75, "Warm White");
    Thermostat thermostat1(102, "Home Thermostat", true, "Hallway", 22.5, "Cooling", 24);
    SecurityCamera cam1(103, "Front Door Camera", false, "Entrance", 1080, true);
    SmartPlug plug1(104, "Kitchen Plug", true, "Kitchen", 1.2, 30);
    light1.displayInfo();
    thermostat1.getStatus();
    cam1.turnOn();
    cam1.displayInfo();
    plug1.turnOff();
    plug1.displayInfo();
    return 0;
}