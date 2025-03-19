#include "PluginVkWrapper.hpp"
#include "Startup.hpp"

namespace ES::Plugin::Wrapper {

void Plugin::Bind()
{
    RegisterSystem<ES::Engine::Scheduler::Startup>(Window::System::CreateWindowSystem);
    RegisterSystem<ES::Engine::Scheduler::Startup>(Window::System::EnableVSync);

    RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::InitVkWrapper);
    RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::AddTextureAndModel);
    RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::AddShaders);
    RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::EnableDepthTest);
    RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::CreatePipeline);
    RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::ChangeClearColor);
    RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::CreateGuiInstance);
    RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::DisplayConfigs);

    RegisterSystem<ES::Engine::Scheduler::Update>(Window::System::PollEvents);
    RegisterSystem<ES::Engine::Scheduler::Update>(Window::System::UpdateKey);
    RegisterSystem<ES::Engine::Scheduler::Update>(Wrapper::System::DrawFrame);
}

} // namespace ES::Plugin::Wrapper
