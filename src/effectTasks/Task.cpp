#include "Task.h"

#include "imgui/imgui.h"


void TaskMenu::showMenu()
{
	for (auto& test : m_Tests) {
		if (ImGui::Button(test.first.c_str())) {
			m_CurrentTest = test.second();
		}
	}

}
TaskMenu::TaskMenu()
{
	m_CurrentTest = this;
}

void TaskMenu::OnImGuiRender()
{
	if (m_CurrentTest == this)
	{
		showMenu();
	}
	else if (m_CurrentTest != this && ImGui::Button("<--"))
	{
		delete m_CurrentTest;
		m_CurrentTest = this;
	}
	else {
        // 此时的current test 是实际运行的子类
		m_CurrentTest->OnImGuiRender();
	}
}

void TaskMenu::OnRender()
{
	if (m_CurrentTest != this)
		m_CurrentTest->OnRender();
}

void TaskMenu::ProcessInput(GLFWwindow *window) {
    if (m_CurrentTest != this) {
        m_CurrentTest->ProcessInput(window);
    } else {
        Task::ProcessInput(window);
    }
}
