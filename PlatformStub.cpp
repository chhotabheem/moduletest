#include "Platform.h"
#include "MesaageQueue.h"
#include "json.hpp"

#include <fstream>
#include <string>
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
            stub::Message msg;
            msg.m_testcase_name = el.value()["name"].get<std::string>();
            msg.m_input = el.value()["input"].get<std::uint32_t>();
            msg.m_expected_op = el.value()["expectedoutput"].get<std::uint64_t>();
            stub::MsgQueue::get_instance().push(msg);
            std::cout << el.key() << " : " << el.value() << "\n";
            std::cout << el.value()["input"] << std::endl;
        }
    }
    return true;
}
