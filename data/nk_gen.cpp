#include <fstream>
#include <random>
#include <iostream>

int main()
{
    constexpr int NUM_CHICKEN = 1'000'000;
    constexpr int ROOF_LENGTH = 1000;

    std::ofstream out("data/nk_input.txt", std::ios::binary);
    if (!out)
    {
        std::cerr << "Failed to open output file\n";
        return 1;
    }

    // first line
    out << NUM_CHICKEN << " " << ROOF_LENGTH << "\n";

    // second line full of pos
    long long pos = 0;
    for (int i = 0; i < NUM_CHICKEN; ++i)
    {
        pos += rand() % 5 + 1;
        out << pos << " ";
    }

    out << '\n';
}
