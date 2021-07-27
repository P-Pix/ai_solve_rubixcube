/**
 * @file Constructor.cpp
 * @author Guillaume LEMONNIER
 * @date 2021-07-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Window.hpp"

Window::Window(void)
{ 
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    m_Window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, m_Window_name, nullptr, nullptr);
    createInstance();
    setupDebugMesage();
    pickPhysicalDevice();
    glfwCreateWindowSurface(m_instance, m_Window, nullptr, &m_Surface);
    createSurface();
    pickPhysicalDevice();
    createImageViews();
    createGraphicsPipeline();
}

Window::~Window(void)
{
    close();
}

void Window::setupDebugMesage(void)
{
    
}
void Window::pickPhysicalDevice(void)
{
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    uint32_t devicecout = 0;
    vkEnumeratePhysicalDeviceGroups(m_instance, &devicecout, nullptr);
    if(devicecout == 0)
    {
        std::cout << "failled to find gpu with vulkan support" << std::endl;
    }
}

void Window::close(void)
{
    for(uint i = 0; i < m_SwapChainImageViews.size(); i ++) 
    {
        vkDestroyImageView(m_device, m_SwapChainImageViews[i], nullptr);
    }
    vkDestroySurfaceKHR(m_instance, m_Surface, nullptr);
    vkDestroyInstance(m_instance, nullptr);
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}