#include "imgui/imgui.h"

#include "VertexBufferLayout.h"
#include "OG7Camera2.h"


OG7Camera2::OG7Camera2()
        : m_ModelVec(glm::vec3(1.0f, 0.0f, 0.0f)), m_ViewVec(glm::vec3(0.0f, 0.0f, -3.0f)), m_Degree(.0f),
          m_PerspectDegree(45.0f), m_cameraPos(0.0f, 0.0f, 3.0f), m_cameraFront(0.0f, 0.0f, -1.0f),
          m_cameraUp(0.0f, 1.0f, 0.0f){
    //开启深度测试
    glEnable(GL_DEPTH_TEST);
    float vertices[] = {
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f
    };

    m_VAO = std::make_unique<VertexArray>();
    m_VBO = std::make_unique<VertexBuffer>(vertices, sizeof(vertices));
    m_VBO->layout.push<float>(3);
    m_VBO->layout.push<float>(2);
    m_VBO->bind();
    m_VAO->addBuffer(*m_VBO);

    m_Shader = std::make_unique<Shader>("../res/shaders/OG6Coordinate2.glsl");
    m_Shader->bind();
    m_Shader->setUniform1i("ourTexture", 0);
    m_Shader->setUniform1i("ourTexture2", 1);

    m_Texture = std::make_unique<Texture>("../res/textures/wall.jpg");
    m_Texture2 = std::make_unique<Texture>("../res/textures/awesomeface.png");
}

OG7Camera2::~OG7Camera2() {

}

void OG7Camera2::OnRender() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

    glm::vec3 cubePositions[] = {
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(2.0f, 5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3(2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f, 3.0f, -7.5f),
            glm::vec3(1.3f, -2.0f, -2.5f),
            glm::vec3(1.5f, 2.0f, -2.5f),
            glm::vec3(1.5f, 0.2f, -1.5f),
            glm::vec3(-1.3f, 1.0f, -1.5f)
    };

    m_Texture->bind(0);
    m_Texture2->bind(1);

    int screenWidth = 800;
    int screenHeight = 600;
    float radius = 10.0f;
    m_View = glm::lookAt(m_cameraPos, m_cameraPos + m_cameraFront, m_cameraUp);

    m_Proj = glm::perspective(glm::radians(m_PerspectDegree), (float) screenWidth / (float) screenHeight, 0.1f, 100.0f);

    for (unsigned int i = 0; i < 10; i++) {
        m_Model = glm::translate(glm::mat4(1.0f), cubePositions[i]);
        float angle = m_Degree * (i + 1);
        m_Model = glm::rotate(m_Model, glm::radians(angle), m_ModelVec);
        m_Shader->SetUniformMat4f("u_MVP", m_Proj * m_View * m_Model);
        m_Renderer->DrawArray(*m_VAO, *m_Shader, m_VBO->GetCount());
    }
}

void OG7Camera2::OnImGuiRender() {
    ImGui::SliderFloat("PerpectiveDegree", &m_PerspectDegree, 0.0f, 360.0f);
    ImGui::SliderFloat("Degree", &m_Degree, -180.0f, 180.0f);
    ImGui::SliderFloat3("Model", &m_ModelVec.x, 0.0f, 1.0f);
    ImGui::SliderFloat3("view", &m_ViewVec.x, -3.0f, 3.0f);
}

void OG7Camera2::OnUpdate(float deltaTime) {
}

void OG7Camera2::ProcessInput(GLFWwindow *window) {
    float cameraSpeed = 0.05f;
    if (glfwGetKey(window, GLFW_KEY_W)) {
        m_cameraPos += cameraSpeed * m_cameraFront;
    }
    if (glfwGetKey(window, GLFW_KEY_S)) {
        m_cameraPos -= cameraSpeed * m_cameraFront;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        m_cameraPos -= glm::normalize(glm::cross(m_cameraFront, m_cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        m_cameraPos += glm::normalize(glm::cross(m_cameraFront, m_cameraUp)) * cameraSpeed;
}