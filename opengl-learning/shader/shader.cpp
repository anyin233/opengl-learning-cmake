#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

shader::shader(const char* vertexShaderPath, const char* fragmentShaderPath){
    
    std::string vertexString;
    std::string fragmentString;

    try{
        auto vertexShaderStream = std::ifstream(vertexShaderPath);
        auto fragmentShaderStream = std::ifstream(fragmentShaderPath);
        std::stringstream vertexStream, fragmentStream;
        vertexStream << vertexShaderStream.rdbuf();
        fragmentStream << fragmentShaderStream.rdbuf();
        vertexString = vertexStream.str();
        fragmentString = fragmentStream.str();
    }catch(std::exception e){
        std::cout << e.what() << std::endl;
    }

    unsigned int vertexShader, fragmentShader;
    vertexShader =  glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* aVertexString = vertexString.c_str();
    const char* aFragmentString = fragmentString.c_str();
    

    char infoLog[512] = {0};
    int len = 512;
    int success = 0;
    glShaderSource(vertexShader, 1, &aVertexString, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, len, NULL, infoLog);
        std::cout << "GL::VERTEX::SHADER::COMPILE::" << infoLog <<std::endl;
    }

    glShaderSource(fragmentShader, 1, &aFragmentString, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader, len, NULL, infoLog);
        std::cout << "GL::FRAGMENT::SHADER::COMPILE::" << infoLog << std::endl;
    }

    this->program = glCreateProgram();
    glAttachShader(this->program, vertexShader);
    glAttachShader(this->program, fragmentShader);
    glLinkProgram(this->program);
    glGetProgramiv(this->program, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(this->program, len, NULL, infoLog);
        std::cout << "GL::PROGRAM::LINK::" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

shader::~shader(){
    glDeleteProgram(this->program);
}

void shader::use(){
    glUseProgram(this->program);
}