#include "Logger.h"
#include <fstream>
#include <iostream>

bool Logger::writeCSV(const std::string& filename, const std::string& data) {
    if (data.empty()) {
        std::cerr << "Logger::writeCSV - empty data string\n";
        return false;
    }

    std::ofstream file(filename, std::ios::app);
    if (!file) {
        std::cerr << "Logger::writeCSV - failed to open file: " << filename << "\n";
        return false;
    }

    file << data << "\n";
    return true;
}
