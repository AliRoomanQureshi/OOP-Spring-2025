#include <iostream>
#include <fstream>

int main() {
    std::ifstream ifs("large_log.txt");
    if (!ifs.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    char buffer[11];
    ifs.read(buffer, 10);
    buffer[10] = '\0';
    std::cout << "First read: " << buffer << std::endl;
    std::cout << "Position after first read: " << ifs.tellg() << std::endl;

    ifs.read(buffer, 10);
    buffer[10] = '\0';
    std::cout << "Second read: " << buffer << std::endl;
    std::cout << "Position after second read: " << ifs.tellg() << std::endl;

    ifs.close();
    return 0;
}
