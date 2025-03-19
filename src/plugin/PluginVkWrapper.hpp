/**************************************************************************
 * VkWrapper v0.0.4
 *
 * VkWrapper is a software package, part of the Engine².
 *
 * This file is part of the Engine² project that is under GPL-3.0 License.
 * Copyright © 2024 by @EngineSquared, All rights reserved.
 *
 * Engine² is a free software: you can redistribute it and/or modify
 * it under the terms of the GPL-3.0 License as published by the
 * Free Software Foundation. See the GPL-3.0 License for more details.
 *
 * @file PluginVkWrapper.hpp
 * @brief VkWrapper plugin declaration.
 *
 * @author @MasterLaplace
 * @version 0.0.4
 * @date 2025-03-19
 **************************************************************************/

#include "APlugin.hpp"

#include "Vk-Wrapper.hpp"
#include "WindowSystem.hpp"

namespace ES::Plugin::Wrapper {

class Plugin : public ES::Engine::APlugin {
  public:
    explicit Plugin(ES::Engine::Core &core) : ES::Engine::APlugin(core){};
    ~Plugin() = default;

    void Bind() final;
};

} // namespace ES::Plugin::Wrapper
