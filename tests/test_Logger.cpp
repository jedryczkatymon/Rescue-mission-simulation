#include "gtest/gtest.h"
#include "../include/Logger.h"
#include <fstream>
#include <cstdio>

class LoggerTest : public ::testing::Test
{
protected:
    std::string test_filename = "test_logger.csv";

    void TearDown() override
    {
        std::remove(test_filename.c_str());
    }

    std::string readFileContent(const std::string &filename)
    {
        std::ifstream file(filename);
        std::string content, line;
        while (std::getline(file, line))
        {
            content += line + "\n";
        }
        return content;
    }
};

TEST_F(LoggerTest, WriteCSV_ValidData_ReturnsTrueAndWritesToFile)
{
    Logger logger;
    std::string data = "col1,col2,col3";
    bool result = logger.writeCSV(test_filename, data);
    ASSERT_TRUE(result);

    std::ifstream file(test_filename);
    ASSERT_TRUE(file.is_open());
    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, data);
}

TEST_F(LoggerTest, WriteCSV_EmptyData_ReturnsFalseAndDoesNotWrite)
{
    Logger logger;
    bool result = logger.writeCSV(test_filename, "");
    ASSERT_FALSE(result);

    std::ifstream file(test_filename);
    EXPECT_FALSE(file.good());
}

TEST_F(LoggerTest, WriteCSV_FileAppendMode_AppendsData)
{
    Logger logger;
    std::string data1 = "row1";
    std::string data2 = "row2";
    ASSERT_TRUE(logger.writeCSV(test_filename, data1));
    ASSERT_TRUE(logger.writeCSV(test_filename, data2));

    std::ifstream file(test_filename);
    ASSERT_TRUE(file.is_open());
    std::string line1, line2;
    std::getline(file, line1);
    std::getline(file, line2);
    EXPECT_EQ(line1, data1);
    EXPECT_EQ(line2, data2);
}

TEST_F(LoggerTest, WriteCSV_InvalidFile_ReturnsFalse)
{
    Logger logger;
    // Try to write to a directory (should fail)
    bool result = logger.writeCSV("/", "data");
    ASSERT_FALSE(result);
}

bool Logger::writeCSV(const std::string &filename, const std::string &data)
{
    if (data.empty())
    {
        std::cerr << "Logger::writeCSV - empty data string\n";
        return false;
    }

    std::ofstream file(filename, std::ios::app);
    if (!file)
    {
        std::cerr << "Logger::writeCSV - failed to open file: " << filename << "\n";
        return false;
    }

    file << data << "\n";
    return true;
}
