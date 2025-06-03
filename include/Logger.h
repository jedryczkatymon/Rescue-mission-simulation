#pragma once
#include <string>

class Logger {
public:
    static bool writeCSV(const std::string& filename, const std::string& data);
};
