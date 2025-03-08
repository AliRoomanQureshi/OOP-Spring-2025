#include <iostream>
#include <string>

using namespace std;

class AlarmSystem {
private:
    string securityLevel;

public:
    AlarmSystem(const string& level = "Low") {
        setSecurityLevel(level);
    }

    void setSecurityLevel(const string& level) {
        securityLevel = level;
    }

    string getSecurityLevel() const {
        return securityLevel;
    }

    void displayAlarmSystemDetails() const {
        cout<<"Alarm System Security Level: "<<securityLevel<<endl;
    }
};

class SmartHome {
private:
    string homeName;  
    AlarmSystem alarm;

public:
    SmartHome(const string& name, const string& securityLevel)
        : homeName(name), alarm(securityLevel) {
        cout<<"SmartHome \""<<homeName<<"\" with AlarmSystem created."<<endl;
    }

    
    ~SmartHome() {
        cout<<"SmartHome \""<<homeName<<"\" with AlarmSystem destroyed."<<endl;
    }

    
    void displayDetails() const {
        cout<<"Smart Home Name: "<<homeName<<endl;
        alarm.displayAlarmSystemDetails();
    }
};


int main() {
    SmartHome home1("MySmartHome", "High");
    home1.displayDetails();
    cout<<endl;

    SmartHome home2("VacationHome", "Medium");
    home2.displayDetails();

    return 0;
}
