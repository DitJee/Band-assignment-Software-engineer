#include <iostream>
#include "bbr.h"
#include "scr.h"

int main()
{
    std::cout << "running tests" << std::endl;

    BBR::test();
    SCR::test();

    return 0;
}