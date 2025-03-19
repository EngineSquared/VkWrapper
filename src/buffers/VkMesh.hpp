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
 * @date 2025-03-11
 **************************************************************************/

#ifndef VKMESH_HPP_
#define VKMESH_HPP_

#include "DebugMessenger.hpp"
#include "VkVertex.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <array>

namespace ES::Plugin::Wrapper {

/**
 * @brief VkMesh structure.
 *
 * This structure is used to represent a vertex in the Vulkan API.
 * It contains the position and color of the vertex.
 */
struct VkMesh : public Object::Component::Mesh {
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;

    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;
    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void *> uniformBuffersMapped;

    /**
     * @brief Construct a new VkMesh object.
     *
     * @param name  The name of the mesh.
     */
    explicit VkMesh(const std::string &name) : Object::Component::Mesh(name) {}

    /**
     * @brief Construct a new VkMesh object from a Mesh object.
     *
     * @param mesh  The Mesh object.
     */
    explicit VkMesh(const Object::Component::Mesh &mesh) : Object::Component::Mesh(mesh) {}

    /**
     * @brief Default constructor.
     */
    VkMesh() = default;

    /**
     * @brief Copy constructor.
     */
    VkMesh(const VkMesh &other) = default;

    /**
     * @brief Move constructor.
     */
    VkMesh(VkMesh &&other) noexcept = default;

    /**
     * @brief Copy assignment operator.
     */
    VkMesh& operator=(const VkMesh &other) = default;

    /**
     * @brief Move assignment operator.
     */
    VkMesh& operator=(VkMesh &&other) noexcept = default;
};

} // namespace ES::Plugin::Wrapper

#endif /* !VKMESH_HPP_ */
