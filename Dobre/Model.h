#ifndef MODEL_H
#define MODEL_H

#include <GL/glew.h>

class Model {
public:
    Model(float x);
    ~Model();

    void draw();

private:
    GLuint VAO;
    GLuint VBO = 0;
    GLsizei vertexCount;
};

#endif // MODEL_H
