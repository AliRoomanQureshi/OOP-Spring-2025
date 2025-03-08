#include<iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;
public:
    Device(int id,bool stat){
        deviceID=id;
        status=stat;
    }
    virtual void displayDetails(){
        cout<<"Device ID:"<<deviceID<<endl;
        cout<<"Status:"<<(status?"ON":"OFF")<<endl;
    }
};

class SmartPhone : virtual public Device{
protected:
    float screenSize;
public:
    SmartPhone(int id,bool stat,float screen):Device(id,stat){
        screenSize=screen;
    }
    void displayDetails(){
        Device::displayDetails();
        cout<<"Screen Size:"<<screenSize<<" inches"<<endl;
    }
};

class SmartWatch : virtual public Device{
protected:
    bool heartRateMonitor;
public:
    SmartWatch(int id,bool stat,bool hrMonitor):Device(id,stat){
        heartRateMonitor=hrMonitor;
    }
    void displayDetails(){
        Device::displayDetails();
        cout<<"Heart Rate Monitor:"<<(heartRateMonitor?"Available":"Not Available")<<endl;
    }
};

class SmartWearable : public SmartPhone,public SmartWatch{
private:
    int stepCounter;
public:
    SmartWearable(int id,bool stat,float screen,bool hrMonitor,int steps)
    :Device(id,stat),SmartPhone(id,stat,screen),SmartWatch(id,stat,hrMonitor){
        stepCounter=steps;
    }
    void displayDetails(){
        SmartPhone::displayDetails();
        cout<<"Heart Rate Monitor:"<<(heartRateMonitor?"Available":"Not Available")<<endl;
        cout<<"Step Counter:"<<stepCounter<<" steps"<<endl;
    }
};

int main(){
    int id,steps;
    bool status,hrMonitor;
    float screen;
    cout<<"Enter Device ID:";cin>>id;
    cout<<"Enter Status (1 for ON, 0 for OFF):";cin>>status;
    cout<<"Enter Screen Size:";cin>>screen;
    cout<<"Is Heart Rate Monitor Available (1 for Yes, 0 for No):";cin>>hrMonitor;
    cout<<"Enter Step Counter:";cin>>steps;
    SmartWearable device(id,status,screen,hrMonitor,steps);
    cout<<"Device Details:"<<endl;
    device.displayDetails();
    return 0;
}
