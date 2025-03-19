/**************************************************************************
 * VkWrapper v0.0.4
 *
 * VkWrapper is a software package, part of the Engine².
 *
 * This file is part of the VkWrapper project that is under GPL-3.0 License.
 * Copyright © 2024 by @EngineSquared, All rights reserved.
 *
 * VkWrapper is a free software: you can redistribute it and/or modify
 * it under the terms of the GPL-3.0 License as published by the
 * Free Software Foundation. See the GPL-3.0 License for more details.
 *
 * @file VkVertex.hpp
 * @brief VkVertex class declaration.
 *
 * @author @MasterLaplace
 * @version 0.0.4
 * @date 2024-11-03
 **************************************************************************/

#ifndef VKVERTEX_HPP_
#define VKVERTEX_HPP_

#include "DebugMessenger.hpp"
#include "component/Mesh.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <array>

namespace ES::Plugin::Wrapper {

/**
 * @brief VkVertex structure.
 *
 * This structure is used to represent a vertex in the Vulkan API.
 * It contains the position and color of the vertex.
 *
 * @example "Get the binding and attribute descriptions for the vertex."
 * @code
 * auto bindingDescription = VkVertex::GetBindingDescription();
 * auto attributeDescriptions = VkVertex::GetAttributeDescriptions();
 * @endcode
 */
struct VkVertex : public Object::Component::Vertex {
    /**
     * @brief Construct a new VkVertex object.
     *
     * @param pos  The position of the vertex.
     * @param color  The color of the vertex.
     * @param texCoord  The texture coordinate of the vertex.
     */
    VkVertex(const glm::vec3 &pos, const glm::vec3 &color, const glm::vec2 &texCoord);

    /**
     * @brief Get the Binding Description object for the vertex.
     *
     * @return VkVertexInputBindingDescription  The binding description.
     */
    static VkVertexInputBindingDescription GetBindingDescription();

    /**
     * @brief Get the Attribute Descriptions object for the vertex.
     *
     * @return std::array<VkVertexInputAttributeDescription, 3>  The attribute descriptions.
     */
    static std::array<VkVertexInputAttributeDescription, 3> GetAttributeDescriptions();
};

const std::vector<VkVertex> VERTICES = {
    {{-0.5f, -0.5f, 0.0f},  {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.5f, -0.5f, 0.0f},   {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
    {{0.5f, 0.5f, 0.0f},    {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
    {{-0.5f, 0.5f, 0.0f},   {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},

    {{-0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.5f, -0.5f, -0.5f},  {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
    {{0.5f, 0.5f, -0.5f},   {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
    {{-0.5f, 0.5f, -0.5f},  {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
};

const std::vector<uint32_t> INDICES = {0, 1, 2, 2, 3, 0, 4, 5, 6, 6, 7, 4};

} // namespace ES::Plugin::Wrapper

#endif /* !VKVERTEX_HPP_ */
