#include <iostream>
#include <fstream>

int main() {
    std::ofstream ofs("config.txt");
    ofs << "AAAAA" << "BBBBB" << "CCCCC";
    ofs.close();

    std::fstream fs("config.txt", std::ios::in | std::ios::out);
    if (!fs.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    fs.seekp(5, std::ios::beg);
    fs.write("XXXXX", 5);
    fs.close();

    std::ifstream ifs("config.txt");
    if (!ifs.is_open()) {
        std::cerr << "Error opening the file for reading!" << std::endl;
        return 1;
    }
    std::string content;
    std::getline(ifs, content);
    std::cout << "File content after update: " << content << std::endl;
    ifs.close();
    return 0;
}
