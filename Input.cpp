#include "Input.h"

#include <iostream>

namespace prod
{
    std::uint32_t Input::get()
    {
        std::cout << "Enter the number" << std::endl;
        std::uint32_t val;
        std::cin >> val;
        return val;
    }
} // namespace prod