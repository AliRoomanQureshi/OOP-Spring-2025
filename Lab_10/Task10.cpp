#include <iostream>
#include <fstream>

int main() {
    std::ifstream ifs("data_records.txt");
    if (!ifs.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    int offset = 0;
    std::string line;
    for (int i = 0; i < 2; ++i) {
        std::getline(ifs, line);
        offset += line.length() + 1;
    }

    ifs.seekg(offset, std::ios::beg);
    std::getline(ifs, line);
    std::cout << "Third record: " << line << std::endl;

    ifs.close();
    return 0;
}
