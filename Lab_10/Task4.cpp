#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream inputFile("vehicles.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file 'vehicles.txt'." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.empty() || line.substr(0, 2) == "//") {
            continue;
        }

        istringstream ss(line);
        string type, id, name, yearStr, extraData, certification;
        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, yearStr, ',');
        getline(ss, extraData, ',');
        getline(ss, certification);

        int year = stoi(yearStr);

        cout << "Type         : " << type << endl;
        cout << "ID           : " << id << endl;
        cout << "Name         : " << name << endl;
        cout << "Year (int)   : " << year << endl;
        cout << "Extra Data   : " << extraData << endl;
        cout << "Certification: " << certification << endl;

        if (type == "AutonomousCar") {
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos) {
                string versionStr = extraData.substr(colonPos + 1);
                float softwareVersion = stof(versionStr);
                cout << " Software Version (float) for " << id << ": " << softwareVersion << endl;
            } else {
                cout << " Invalid format for Software Version in AutonomousCar." << endl;
            }
        }
        else if (type == "ElectricVehicle") {
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos) {
                string batteryStr = extraData.substr(colonPos + 1);
                int batteryCapacity = stoi(batteryStr);
                cout << " Battery Capacity (int) for " << id << ": " << batteryCapacity << " kWh" << endl;
            } else {
                cout << " Invalid format for Battery in ElectricVehicle." << endl;
            }
        }

        cout << "------------------------------------" << endl;
    }

    inputFile.close();
    return 0;
}
