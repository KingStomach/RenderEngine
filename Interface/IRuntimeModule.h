#pragma once
#include "Interface.h"

namespace RenderEngine
{
    class IRuntimeModule
    {
    public:
        IRuntimeModule() {};
        virtual ~IRuntimeModule() {};

        virtual int Initialize() = 0;
        virtual void Finalize() = 0;
        virtual void Tick() {};
    private:
        DISALLOW_COPY_AND_MOVE(IRuntimeModule);
    };
}