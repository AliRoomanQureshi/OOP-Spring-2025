#include <iostream>
#include <fstream>

int main() {
   
    std::ofstream ofs("sensor_log.txt");

    if (!ofs.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    ofs << "Sensor 1: Temperature = 25.3 C\n";
   
    std::streampos pos1 = ofs.tellp();
    std::cout << "Position after first write: " << pos1 << std::endl;

    ofs << "Sensor 2: Temperature = 26.1 C\n";
    std::streampos pos2 = ofs.tellp();
    std::cout << "Position after second write: " << pos2 << std::endl;

    ofs.close();
    
    return 0;
}
