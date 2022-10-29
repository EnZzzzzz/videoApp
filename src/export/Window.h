#pragma once
#include "GLFW/glfw3.h"
#include "effectTasks/Task.h"
#include "Context.h"


class Window : public Context
{
public:
	int m_Width, m_Height;
	Window(int width, int height, const char* name);
	~Window();

	void show(Task* task) override;

private:
	GLFWwindow* m_Window;
	void processInput(GLFWwindow* window);
};
