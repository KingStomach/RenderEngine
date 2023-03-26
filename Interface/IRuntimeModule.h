#pragma once
#include "Interface.h"
#include <atomic>
#include <concepts>
#include <concurrent_queue.h>
#include <thread>

namespace RenderEngine
{
    template <class Module, class Command>
    struct is_moudle_command_match : std::false_type {};

    enum class MODULE_STATE :char { BEGIN, LOOPING, ENDING, END };

    template <class Derived, class Command>
    requires is_moudle_command_match<Derived, Command>::value
    class IRuntimeModule
    {
    public:
        constexpr IRuntimeModule() : m_state(MODULE_STATE::BEGIN) {};
        virtual ~IRuntimeModule() {}

        int Initialize() { return static_cast<Derived*>(this)->InitializeImpl(); }
        void Finalize() { static_cast<Derived*>(this)->FinalizeImpl(); }

    protected:
        void sendCommand(const Command& command) { m_pipe.push(command); }
        template <class ...Args>
        void sendCommand(const Args& ... args) { m_pipe.push(std::make_shared<Command>(args)); }

        using CommandPipe = concurrency::concurrent_queue<Command>;
        using MCommand = Command;

        std::thread m_thread;
        CommandPipe m_pipe;
        std::atomic<MODULE_STATE> m_state;

        void runThread()
        {
            while (m_state < MODULE_STATE::ENDING) Tick();
            m_state = MODULE_STATE::END;
            return;
        };
        void Tick() { static_cast<Derived*>(this)->TickImpl(); }

    private:
        DISALLOW_COPY_AND_MOVE(IRuntimeModule);
    };
}