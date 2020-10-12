#include "BusLogic.h"
#include "Input.h"
#include "Output.h"

namespace prod
{
    void BusLogic::calculate()
    {
        while (true)
        {
            Input ip;
            std::uint32_t val = ip.get();
            std::uint64_t res = val * val;
            Output op;
            op.write(res);
        }

        return;
    }
} // namespace prod