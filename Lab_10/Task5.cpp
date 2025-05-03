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
            size_t pos = extraData.find(':');
            if (pos != string::npos) {
                string versionStr = extraData.substr(pos + 1);
                float softwareVersion = stof(versionStr);
                cout << "Software Version (float) for " << id << ": " << softwareVersion << endl;
            } else {
                cout << "Error: ':' not found in AutonomousCar extraData." << endl;
            }
        }
        else if (type == "ElectricVehicle") {
            size_t pos = extraData.find(':');
            if (pos != string::npos) {
                string batteryStr = extraData.substr(pos + 1);
                int battery = stoi(batteryStr);
                cout << "Battery Capacity (int) for " << id << ": " << battery << " kWh" << endl;
            } else {
                cout << "Error: ':' not found in ElectricVehicle extraData." << endl;
            }
        }
        else if (type == "HybridTruck") {
            size_t cargoPos = extraData.find("Cargo:");
            size_t pipePos = extraData.find('|');
            size_t batteryPos = extraData.find("Battery:");

            if (cargoPos != string::npos && pipePos != string::npos && batteryPos != string::npos) {
                string cargoStr = extraData.substr(cargoPos + 6, pipePos - (cargoPos + 6));
                string batteryStr = extraData.substr(batteryPos + 8);

                int cargo = stoi(cargoStr);
                int battery = stoi(batteryStr);

                cout << "Cargo Capacity (int) for " << id << ": " << cargo << " kg" << endl;
                cout << "Battery Capacity (int) for " << id << ": " << battery << " kWh" << endl;
            } else {
                cout << "Error: Failed to parse HybridTruck extraData properly." << endl;
            }
        }
        else {
            cout << "Error: Unknown vehicle type '" << type << "'." << endl;
        }

        cout << "------------------------------------" << endl;
    }

    inputFile.close();
    return 0;
}