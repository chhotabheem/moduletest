#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include "Message.h"

#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>
#include <iostream>

namespace stub
{
    class MsgQueue
    {
    private:
        std::queue<Message> m_queue;
        std::mutex m_que_mutex;
        std::condition_variable m_con_var;
        const int m_max_que_size;
        explicit MsgQueue(const int max_que_size) : m_max_que_size(max_que_size) {}

    public:
        static MsgQueue &get_instance()
        {
            static MsgQueue msgq(100);
            return msgq;
        }
        ~MsgQueue() {}
        MsgQueue(const MsgQueue &) = delete;
        MsgQueue(const MsgQueue &&) = delete;
        MsgQueue &operator=(const MsgQueue &&) = delete;
        MsgQueue &operator=(const MsgQueue &) = delete;

        void push(Message &msg)
        {
            std::unique_lock<std::mutex> locker(m_que_mutex);
            if (m_queue.size() < m_max_que_size)
            {
                m_queue.push(msg);
                locker.unlock();
                m_con_var.notify_one();
            }
            else
            {
                std::cout << "push(): ERR queue is full. dropping the message" << std::endl;
            }
        }

        Message front()
        {
            std::unique_lock<std::mutex> locker(m_que_mutex);
            m_con_var.wait(locker, [&]() {
                return !m_queue.empty();
            });
            Message msg = m_queue.front();
            return msg;
        }

        Message pop()
        {
            std::unique_lock<std::mutex> locker(m_que_mutex);
            m_con_var.wait(locker, [&]() {
                return !m_queue.empty();
            });
            Message msg = m_queue.front();
            m_queue.pop();
            return msg;
        }
    };
} // namespace stub
#endif