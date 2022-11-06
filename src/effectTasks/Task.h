#pragma once

#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Task {
public:
    int frameCount;

    Task() : frameCount(1) {}

    virtual ~Task() = default;

    virtual void OnUpdate(float deltaTime) {}

    virtual void OnRender() {}

    virtual void OnImGuiRender() {}

    virtual void ProcessInput(GLFWwindow *window) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }
};

class TaskMenu : public Task {
private:
    Task *m_CurrentTest;
    std::vector<std::pair<std::string, std::function<Task *()>>> m_Tests;

    void showMenu();

public:
    TaskMenu();

    void OnImGuiRender() override;

    void OnRender() override;

    template<typename T>
    void RegisterTest(const std::string &name) {
        std::cout << "Register test: " << name << std::endl;

        m_Tests.push_back(std::make_pair(name, []() { return new T(); }));
    }
};
