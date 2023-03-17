#pragma once
#include "ICommand.h"
#include "Interface.h"
#include <concurrent_queue.h>
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
        void sendCommand(const std::shared_ptr<RenderEngine::Command>& pCommand) { m_pipe.push(pCommand); }
    protected:
        std::thread m_thread;
        concurrency::concurrent_queue<std::shared_ptr<RenderEngine::Command>> m_pipe;
    private:
        DISALLOW_COPY_AND_MOVE(IRuntimeModule);
    };
}