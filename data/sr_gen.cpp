#include <fstream>
#include <random>
#include <iostream>

int main()
{
    constexpr size_t NUN_CHAR = 1'000'000;
    constexpr size_t SEED = 42;

    std::ofstream out("data/input.txt", std::ios::binary);
    if (!out)
    {
        std::cerr << "Failed to open output file\n";
        return 1;
    }

    std::mt19937 rng(SEED);
    std::uniform_int_distribution<int> dist(0, 1);

    for (size_t i = 0; i < NUN_CHAR; ++i)
    {
        out << (dist(rng) ? 'S' : 'R');
    }

    out << '\n';
}
