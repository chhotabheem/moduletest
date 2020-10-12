#include "Output.h"
#include <iostream>
namespace prod
{
    void Output::write(std::uint64_t res)
    {
        std::cout << "Result is: " << res << std::endl;
        return;
    }
} // namespace prod