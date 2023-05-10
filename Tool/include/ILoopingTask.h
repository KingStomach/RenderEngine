#pragma once
#include <atomic>
#include <future>
#include <thread>

namespace RenderEngine
{
    template <class Derived>
    class ILoopingTask
    {
    public:
        ILoopingTask() : m_run(false), m_end(false), m_pause(false) {}
        ~ILoopingTask() {}

        auto run()
        {
            //if (m_run || m_pause)
                //return;
            m_run = true;
            return std::async(&ILoopingTask<Derived>::loop, this);
        }

        void resume() noexcept
        {
            m_run = true;
            m_run.notify_one();
        }
        void pause() noexcept { m_run = false; }
        void end() noexcept
        {
            m_run = true;
            m_end = true;
            m_run.notify_one();
        }

    protected:
        using Base = ILoopingTask<Derived>;

        void startImpl() {}

    private:
        auto start() { return static_cast<Derived*>(this)->startImpl(); }
        auto update() { return static_cast<Derived*>(this)->updateImpl(); }

        void loop()
        {
            this->start();

            while (true)
            {
                if (m_end)
                    break;

                if (m_run)
                    this->update();
                else
                    m_run.wait(true);
            }
        }

        std::atomic<bool> m_run;
        std::atomic<bool> m_end;
        std::atomic<bool> m_pause;
    };
}