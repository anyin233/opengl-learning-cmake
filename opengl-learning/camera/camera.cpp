#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "camera.h"

Camera::Camera()
{
    euler_mode = false;
    this->pitch = 0;
    this->yaw = 0;
}

Camera::Camera(glm::vec3 pos, glm::vec3 target, glm::vec3 up)
{
    euler_mode = false;
    this->pos = pos;
    this->target = target;
    this->up = up;
    this->view = glm::lookAt(pos, pos + target, up);
}

Camera::Camera(glm::vec3 pos, float pitch, float yaw, glm::vec3 up)
{
    euler_mode = true;
    this->pos = pos;
    this->target = glm::vec3(1.0);
    this->pitch = pitch;
    this->yaw = yaw;
    target.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
    target.y = sin(glm::radians(pitch));
    target.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

    target = glm::normalize(target);
    this->up = up;
    this->view = glm::lookAt(pos, pos + target, up);
}

void Camera::moving(Directions dir, float speed)
{
    switch (dir)
    {
    case Directions::FRONT:
        pos += speed * target;
        break;
    case Directions::BACK:
        pos -= speed * target;
        break;
    case Directions::LEFT:
        pos += glm::normalize(glm::cross(target, up)) * speed;
        break;
    case Directions::RIGHT:
        pos -= glm::normalize(glm::cross(target, up)) * speed;
        break;
    }

    this->view = glm::lookAt(pos, pos + target, up);
}

void Camera::moving(double offset_pitch, double offset_yaw, double speed)
{
    if (euler_mode)
    {
        pitch += offset_pitch * speed;
        yaw += offset_yaw * speed;

        if (pitch > 89.0)
            pitch = 89.0;
        if (pitch < -89.0)
            pitch = -89.0;
        target.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
        target.y = sin(glm::radians(pitch));
        target.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
        target = glm::normalize(target);
        this->view = glm::lookAt(pos, pos + target, up);
    }
}