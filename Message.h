#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <cstdint>

namespace stub
{
    class Message
    {
    public:
        std::string m_testcase_name;
        std::uint32_t m_input;
        std::uint64_t m_expected_op;
    };
} // namespace stub
#endif