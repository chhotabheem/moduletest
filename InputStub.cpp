#include "Input.h"
#include "MesaageQueue.h"

using namespace prod;
std::uint32_t Input::get()
{
    return stub::MsgQueue::get_instance().front().m_input;
}