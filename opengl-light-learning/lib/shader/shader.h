#ifndef __SHADER
#define __SHADER

#include <glm/glm.hpp>

class shader
{
private:
    
public:
    shader(const char*, const char*);
    void use();
    ~shader();
    unsigned int program;
    void uniformMat4(const char*, glm::mat4);
    void uniformVec3f(const char*, glm::vec3);
};



#endif