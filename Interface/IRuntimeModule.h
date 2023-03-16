#pragma once
#include "Interface.h"
#include <thread>

namespace RenderEngine
{
    class IRuntimeModule
    {
    public:
        IRuntimeModule() {};
        virtual ~IRuntimeModule() {};

        virtual int Initialize() = 0;
        virtual void Finalize() = 0;
        void Tick() { m_thread.join(); };
    protected:
        std::thread m_thread;
    private:
        DISALLOW_COPY_AND_MOVE(IRuntimeModule);
    };
}