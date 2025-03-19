#include "Surface.hpp"

namespace ES::Plugin::Wrapper {

void Surface::Create(GLFWwindow *window, const VkInstance &instance, VkAllocationCallbacks *allocator)
{
    if (glfwCreateWindowSurface(instance, window, allocator, &_surface) != VK_SUCCESS)
        throw VkWrapperError("Failed to create window surface!");
}

void Surface::Destroy(const VkInstance &instance) { vkDestroySurfaceKHR(instance, _surface, nullptr); }

} // namespace ES::Plugin::Wrapper
