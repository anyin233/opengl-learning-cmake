#ifndef CAMERA_H
#define CAMERA_H
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"

enum Directions{
    FRONT,
    BACK,
    LEFT,
    RIGHT
};

class Camera{
public:
Camera();
Camera(glm::vec3 pos, glm::vec3 target, glm::vec3 up);
Camera(glm::vec3 pos, float pitch, float yaw, glm::vec3 up);
void moving(double offset_pitch, double offset_yaw, double speed);
void moving(Directions dir, float speed);
glm::mat4 getView(){
    return this->view;
};
private:
glm::mat4 view;
glm::vec3 pos;
glm::vec3 target;
glm::vec3 up;
float pitch;
float yaw;
bool euler_mode;
};

#endif