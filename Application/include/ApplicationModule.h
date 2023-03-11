#pragma once
#include "IRuntimeModule.h"
#include "BaseApplication.h"
#include <memory>

namespace RenderEngine {
    class ApplicationModule : public IRuntimeModule
    {
    public:
        ApplicationModule() :m_pApplication(nullptr) {}
        virtual ~ApplicationModule() {};
        virtual int Initialize();
        virtual void Finalize();
        virtual void Tick();

    private:
        std::unique_ptr<REApplication::BaseApplication> m_pApplication;
    };
}