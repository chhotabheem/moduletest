#include "Output.h"
#include <iostream>
#include "MesaageQueue.h"
using namespace prod;

void Output::write(std::uint64_t res)
{
    auto msg = stub::MsgQueue::get_instance().front();
    if (msg.m_expected_op == res)
    {
        std::cout << msg.m_testcase_name << " PASSED" << std::endl;
    }
    else
    {
        std::cout << msg.m_testcase_name << " FAILED" << std::endl;
    }
    stub::MsgQueue::get_instance().pop();
    return;
}
