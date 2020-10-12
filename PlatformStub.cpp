#include "Platform.h"
#include "MesaageQueue.h"
#include "json.hpp"
#include <thread>
#include <fstream>
using namespace prod;
using namespace nlohmann;

bool prod::Platform::init()
{
    std::ifstream tc_file_desc("testcases.json");
    if (!tc_file_desc.is_open())
    {
        return false;
    }
    json j;
    tc_file_desc >> j;
    for (json::iterator it = j.begin(); it != j.end(); ++it)
    {
        std::cout << it.key() << " : " << it.value() << "\n";
        json j2 = it.value();
        for (auto &el : j2.items())
        {
            std::cout << el.key() << " : " << el.value() << "\n";
            std::cout<<el.value()["input"]<<std::endl;
        }
    }
    return false;
}
