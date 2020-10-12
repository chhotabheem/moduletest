#include "BusLogic.h"
#include "Platform.h"

int main()
{
    prod::Platform pf;
    if (!pf.init())
    {
        return -1;
    }
    prod::BusLogic bl;
    bl.calculate();
    return 0;
}