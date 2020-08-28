#ifndef __SHADER
#define __SHADER

class shader
{
private:
    
public:
    shader(const char*, const char*);
    void use();
    ~shader();
    unsigned int program;
};



#endif