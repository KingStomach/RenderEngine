#pragma once
#include "Interface.h"

namespace RenderEngine
{
    template <class Derived>
    class IRuntimeModule : public Single<Derived>
    {
    public:
        IRuntimeModule() {}
        virtual ~IRuntimeModule() {}

        bool initialize() { return static_cast<Derived*>(this)->initializeImpl(); }
        void finalize() { static_cast<Derived*>(this)->finalizeImpl(); }

    protected:
        using Base = IRuntimeModule<Derived>;

    private:
        DISALLOW_COPY_AND_MOVE(IRuntimeModule)
    };
}