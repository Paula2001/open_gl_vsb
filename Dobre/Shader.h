#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

class Shader {
public:
    Shader(const char* vertexSource, const char* fragmentSource);
    ~Shader();

    void use();

private:
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programID;
};

#endif // SHADER_H
