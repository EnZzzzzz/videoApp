#include "glad/glad.h"
#include <iostream>
#include "Window.h"
#include "effectTasks/Task.h"

std::shared_ptr<Context> Context::MakeWindow(int w, int h, const char *name) {
    return std::make_shared<Window>(w, h, name);
}

void error_callback(int error, const char *description) {
    puts(description);
}

void setFramebufferSizeCallback(GLFWwindow *window, int width, int height) {
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
}

Window::Window(int width, int height, const char *name) {
    /* Initialize the library */
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) std::cout << "Failed to init window" << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(width, height, "test", NULL, NULL);
    if (!m_Window) {
        glfwTerminate();
        std::cout << "Failed to create window" << std::endl;
    }
    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    std::cout << "Created Window, OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    glfwSwapInterval(1);

}

Window::~Window() {
    glfwDestroyWindow(m_Window);

    glfwTerminate();
}

void Window::processInput(GLFWwindow *window) {
    if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_Window, true);
}

void Window::show(Task *task) {
    while (!glfwWindowShouldClose(m_Window))
    {
        processInput(m_Window);
        setFramebufferSizeCallback(m_Window, m_Width, m_Height);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        if (task) {
            task->OnUpdate(0.0f);
            task->OnRender();
        }


        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }

}
