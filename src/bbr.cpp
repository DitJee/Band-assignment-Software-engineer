#include "bbr.h"
#include <iostream>
#include <cassert>

namespace BBR
{
    const std::string BAD_BOY = "Bad boy";
    const std::string GOOD_BOY = "Good boy";
    const std::string ERROR_INVALID_STR_LENGTH = "invalid str length";
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

    std::cout << "All tests for Boss Baby's Revenge passed!" << std::endl;
}
