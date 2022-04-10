#include "utilities/Time.h"
#include "utilities/Input.h"
#include "utilities/Window.h"
#include "scenes/MainScene.h"

#pragma warning(push, 0)
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <iostream>
#include <fstream>
#pragma warning(pop)

// Global objects
Time g_Time;
Input g_Input;
Window g_Window;

int main() {
    // Initialize OpenGL
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    // Create window
    g_Window.Initialize(1920, 1080, "Rubik's cube");
    if (!g_Window) {
        glfwTerminate();
        std::cout << "Failed to create GLFW window\n";
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(g_Window);
    
    // Load glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n";
        return EXIT_FAILURE;
    }
    
    // Set callbacks
    glfwSetFramebufferSizeCallback(g_Window, framebuffer_size_callback);
    glfwSetCursorPosCallback(g_Window, mouse_callback);
    glfwSetScrollCallback(g_Window, scroll_callback);
    
    // Main scene
    MainScene main_scene;
    main_scene.PreRun();
    main_scene.CreateScene();
    main_scene.Run();
    main_scene.PostRun();
    
    // End of application
    glfwSetWindowShouldClose(g_Window, true);
    glfwTerminate();
    return EXIT_SUCCESS;
}
