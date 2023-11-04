#include "Shader.h"
#include <cstddef>

Shader::Shader(const char* vertexSource, const char* fragmentSource) {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    programID = glCreateProgram();
    glAttachShader(programID, fragmentShader);
    glAttachShader(programID, vertexShader);
    glLinkProgram(programID);
}

Shader::~Shader() {
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteProgram(programID);
}

void Shader::use() {
    glUseProgram(programID);
}
