#include "scr.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

namespace SCR
{
    const std::string NK_INPUT_SMALL_0 = "data/nk_input_small_0.txt";
    const std::string NK_INPUT_SMALL_1 = "data/nk_input_small_1.txt";
    const std::string NK_INPUT_LARGE = "data/nk_input_large.txt";
    const std::string ERROR_INVALID_FILE_PATH = "invalid file path";
}

int SCR::numMaxChickenCanProtect(const std::string &path)
{
    std::ifstream in(path, std::ios::binary);
    if (!in)
    {
        throw std::runtime_error(ERROR_INVALID_FILE_PATH);
    }

    long long n; // handle 1e09
    int k;
    in >> n;
    in >> k;

    if (n < 1)
    {
        return 0;
    }

    std::vector<long long> pos(n);
    for (long long i = 0; i < n; ++i)
    {
        in >> pos[i];
    }

    int count = 0;
    // iter sliding window
    int l = 0;
    for (int r = 0; r < n; ++r)
    {
        // assume array is always sorted.
        while (pos.at(r) - pos.at(l) >= k)
        {
            ++l;
        }
        count = std::max(count, r - l + 1);
    }

    return count;
}

void SCR::test()
{
    std::cout << "[Superman's Chicken Rescue] running tests" << std::endl;

    {
        try
        {
            numMaxChickenCanProtect("hehe.txt");
            assert(false);
        }
        catch (const std::exception &err)
        {
            assert(std::string(err.what()) == ERROR_INVALID_FILE_PATH);
        }

        const int res_0 = numMaxChickenCanProtect(NK_INPUT_SMALL_0);
        const int res_1 = numMaxChickenCanProtect(NK_INPUT_SMALL_1);
        const int res_2 = numMaxChickenCanProtect(NK_INPUT_LARGE);

        assert(res_0 == 2);
        assert(res_1 == 4);
        assert(res_2 == 372);
    }

    std::cout << "[Superman's Chicken Rescue] All tests passed!" << std::endl;
}
