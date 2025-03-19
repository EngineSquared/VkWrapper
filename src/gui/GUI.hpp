/*
** EPITECH PROJECT, 2025
** VkWrapper-Test [WSL : Ubuntu]
** File description:
** GUI
*/

#ifndef GUI_HPP_
#define GUI_HPP_

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"
#include "Buffer.hpp"
#include "QueueFamilies.hpp"
#include <memory>

namespace ES::Plugin::Wrapper {

/**
 * @brief GUI class.
 *
 * @example "Usage of the GUI class:"
 * @code
 * ES::Plugin::Wrapper::GUI::CreateInfo info = {};
 * info.window = window;
 * info.instance = instance;
 * info.physicalDevice = physicalDevice;
 * info.device = device;
 * info.queueFamily = queueFamily;
 * info.queue = queue;
 * info.minImageCount = minImageCount;
 * info.descriptorPool = descriptorPool;
 * info.renderPass = renderPass;
 * info.allocator = allocator;
 * ES::Plugin::Wrapper::GUI::CreateInstance(info);
 * ES::Plugin::Wrapper::GUI::GetInstance().Render(clear_color, commandBuffer);
 * ES::Plugin::Wrapper::GUI::DestroyInstance();
 */
class GUI {
  public:
    struct CreateInfo {
        GLFWwindow *window;
        VkInstance instance;
        VkPhysicalDevice physicalDevice;
        VkDevice device;
        uint32_t queueFamily;
        VkQueue queue;
        uint32_t minImageCount;
        VkDescriptorPool descriptorPool;
        VkRenderPass renderPass;
        const VkAllocationCallbacks *allocator;
    };

    static inline void CreateInstance(const CreateInfo &info)
    {
        if (_instance == nullptr)
        _instance = std::make_unique<GUI>(info);
    }

    static inline void DestroyInstance()
    {
        if (_instance != nullptr)
        _instance.reset();
    }

    static inline GUI &GetInstance()
    {
        if (_instance == nullptr)
            throw std::runtime_error("GUI instance not created!");
        return *_instance;
    }

    /**
     * @brief Protected GUI constructor.
     *
     * This ensures that the GUI class can only be instantiated through
     * the CreateInstance method.
     */
    GUI(const CreateInfo &info);

    /**
     * @brief Protected GUI destructor.
     *
     * This ensures that the GUI class can be properly destroyed.
     */
    ~GUI();


    /**
     * @brief Deleted copy constructor.
     *
     * This prevents copying of the GUI instance.
     *
     * @param copy The instance to copy.
     */
    GUI(const GUI &copy) = delete;

    /**
     * @brief Deleted copy assignment operator.
     *
     * This prevents assignment of the GUI instance.
     *
     * @param copy The instance to assign.
     * @return T& A reference to the assigned instance.
     */
    GUI &operator=(const GUI &copy) = delete;

    static inline void Resize() { ImGui_ImplVulkan_SetMinImageCount(2); }

    void Render(const glm::vec4 &clear_color, const VkCommandBuffer &commandBuffer);

    static void check_vk_result(VkResult err);

  private:
    static inline std::unique_ptr<GUI> _instance = nullptr;
    VkPipelineCache _pipelineCache = VK_NULL_HANDLE;
    bool _show_demo_window = true;
    bool _show_another_window = false;
    ImGuiIO *_io = nullptr;
};

} // namespace ES::Plugin::Wrapper

#endif /* !GUI_HPP_ */
