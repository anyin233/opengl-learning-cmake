#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "../lib/camera/camera.h"
#include "../lib/shader/shader.h"

int windowHeight = 600;
int windowWidth = 800;

double lastX = windowWidth / 2.0;
double lastY = windowWidth / 2.0;

bool firstMouse = true;

float fov = 45.0f;

Camera camera;

void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void FramebufferSizeCallback(GLFWwindow *window, int width, int height);
void processKey(GLFWwindow *window);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight, "Light-learning", NULL, NULL);
    if (window == nullptr)
    {
        std::cout << "Cannot create window";
        glfwTerminate();
        return -1;
    }
    else
    {
        glfwMakeContextCurrent(window);
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Cannot init glad";
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, windowWidth, windowHeight);
    glEnable(GL_DEPTH_TEST);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    //初始化窗口完毕

    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,

        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f};

    unsigned int VAO, VBO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    shader sd = shader("glsl/vertex.glsl", "glsl/obj_fragment.glsl");

    auto camPos = glm::vec3(0.0f, 0.0f, 6.0f);
    auto camTg = glm::vec3(0.0f, 0.0f, 0.0f);
    auto camUp = glm::vec3(0.0f, 1.0f, 0.0f);
    camera = Camera(camPos, 0.0, -90.0, camUp, fov);

    auto model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(20.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    auto proj = glm::mat4(1.0f);
    proj = glm::perspective(double(glm::radians(fov)), double(windowWidth / windowHeight), 0.1, 100.0);


    auto lightPos = glm::vec3(1.2f, 1.0f, 2.0f);
    sd.use();
    sd.uniformMat4("model", model);
    sd.uniformMat4("view", camera.getView());
    sd.uniformMat4("projection", proj);
    sd.uniformVec3f("lightColor", glm::vec3(1.0f));
    sd.uniformVec3f("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
    sd.uniformVec3f("lightPos", lightPos);

    shader lightsd("glsl/vertex.glsl", "glsl/light_fragment.glsl");
    
    auto lightModel = glm::translate(model, lightPos);
    lightModel = glm::scale(lightModel, glm::vec3(0.2f));

    lightsd.use();
    lightsd.uniformMat4("model", lightModel);
    lightsd.uniformMat4("view", camera.getView());
    lightsd.uniformMat4("projection", proj);

    while (!glfwWindowShouldClose(window))
    {
        processKey(window);
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        proj = glm::perspective(double(glm::radians(fov)), double(windowWidth / windowHeight), 0.1, 100.0);
        sd.use();
        sd.uniformMat4("view", camera.getView());
        sd.uniformMat4("projection", proj);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        lightsd.use();
        lightsd.uniformMat4("view", camera.getView());
        lightsd.uniformMat4("projection", proj);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glfwSwapBuffers(window);
    }
}

void FramebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    double xoffset = xpos - lastX;
    double yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;
    camera.moving(yoffset, xoffset, 0.05);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    fov += yoffset;
    if (fov > 60.0)
    {
        fov = 60.0;
    }
    if (fov < 1.0)
    {
        fov = 1.0;
    }
}
void processKey(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}