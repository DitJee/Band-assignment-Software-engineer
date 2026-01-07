#include "bbr.h"
#include <iostream>
#include <cassert>
#include <fstream>

namespace BBR
{
    const std::string BAD_BOY = "Bad boy";
    const std::string GOOD_BOY = "Good boy";
    const std::string ERROR_INVALID_FILE_PATH = "invalid file path";
    const std::string ERROR_INVALID_STR_LENGTH = "invalid str length";
    const std::string TEST_FILE_PATH = "data/input.txt";

}

std::string BBR::isGoodBoy_Simple(const std::string &str)
{
    // validate range
    if (str.empty() || str.length() > 1'000'000)
    {
        throw std::runtime_error(ERROR_INVALID_STR_LENGTH);
    }

    if (str.at(0) == 'R')
    {
        return BAD_BOY;
    }

    int balance = 0;
    for (const char c : str)
    {
        if (c == 'S')
        {
            ++balance;
        }
        else if (c == 'R')
        {
            if (balance > 0)
            {
                --balance;
            }
        }
        else
        {
            // disable this for now
            // since it is not stated in the requirement
            // throw std::runtime_error("invalid char");
        }
    }

    return (balance == 0) ? GOOD_BOY : BAD_BOY;
}

std::string BBR::isGoodBoy_ReadFile(const std::string &path)
{
    std::ifstream in(path, std::ios::binary);
    if (!in)
    {
        throw std::runtime_error(ERROR_INVALID_FILE_PATH);
    }

    int balance = 0;
    char c;
    while (in.get(c))
    {
        if (c == 'S')
        {
            ++balance;
        }
        else if (c == 'R')
        {
            if (balance > 0)
            {
                --balance;
            }
        }
        else
        {
            // disable this for now
            // since it is not stated in the requirement
            // throw std::runtime_error("invalid char");
        }
    }

    return (balance == 0) ? GOOD_BOY : BAD_BOY;
}

void BBR::test()
{
    std::cout << "running test for Boss Baby's Revenge" << std::endl;

    // simple test
    {

        try
        {
            std::string test_1 = "";
            isGoodBoy_Simple(test_1);
            assert(false); // should not reach
        }
        catch (const std::runtime_error &err)
        {
            assert(std::string(err.what()) == ERROR_INVALID_STR_LENGTH);
        }
        try
        {
            std::string test_2;
            test_2.reserve(1'000'001);
            test_2.append(1'000'001, 'S');
            isGoodBoy_Simple(test_2);
            assert(false); // should not reach
        }
        catch (std::runtime_error err)
        {
            assert(std::string(err.what()) == ERROR_INVALID_STR_LENGTH);
        }

        assert(isGoodBoy_Simple("SRSSRRR") == GOOD_BOY);
        assert(isGoodBoy_Simple("RSSRR") == BAD_BOY);
        assert(isGoodBoy_Simple("SSSRRRRS") == BAD_BOY);
        assert(isGoodBoy_Simple("SRRSSR") == BAD_BOY);
        assert(isGoodBoy_Simple("SSRSRR") == GOOD_BOY);
    }

    // read file test
    {
        try
        {
            std::string false_file_path = "data/hehe.txt";
            isGoodBoy_ReadFile(false_file_path);
            assert(false); // should not reach
        }
        catch (std::runtime_error err)
        {
            assert(std::string(err.what()) == ERROR_INVALID_FILE_PATH);
        }

        assert(isGoodBoy_ReadFile(TEST_FILE_PATH) == BAD_BOY);
    }

    std::cout << "All tests for Boss Baby's Revenge passed!" << std::endl;
}
