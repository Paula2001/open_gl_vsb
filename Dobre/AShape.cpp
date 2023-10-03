#include "AShape.h"
#include "StringMan.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
AShape* AShape::setColor(char color) {
    const char* fragment_shader =
        "#version 330\n"
        "out vec4 frag_colour;"
        "void main () {"
        "     color"
        "}";

    const char* needle = "color";

    const char* r;
    const char* g;
    const char* b;
    const char* p;
    const char* w;

    switch (color) {
    case 'r':
        r = "frag_colour = vec4(1.0, 0.0, 0.0, 1.0);";
        this->color = StringMan::replace(needle, r, fragment_shader);
        break;
    case 'g':
        g = "frag_colour = vec4(0.0, 1.0, 0.0, 1.0);";
        this->color = StringMan::replace(needle, g, fragment_shader);
        break;
    case 'b':
        b = "frag_colour = vec4(0.0, 0.0, 1.0, 1.0);";
        this->color = StringMan::replace(needle, b, fragment_shader);
        break;
    case 'p':
        p = "frag_colour = vec4(1.0, 0.0, 1.0, 1.0);";
        this->color = StringMan::replace(needle, p, fragment_shader);
        break;
    default:
        w = "frag_colour = vec4(1.0, 1.0, 1.0, 1.0);";
        this->color = StringMan::replace(needle, w, fragment_shader);
        break;
    }

    return this;
}
AShape* AShape::setPostion() {
    this->position =
        "#version 330\n"
        "layout(location=0) in vec3 vp;"
        "void main () {"
        "     gl_Position = vec4 (vp, 1.0);"
        "}";
    return this;
}
AShape* AShape::setShader()
{
    //vertex buffer object (VBO)
    float points[] = {
    0.0f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
    };
    GLuint VBO = 0;
    glGenBuffers(1, &VBO); // generate the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points,
        GL_STATIC_DRAW);
    //vertex attribute object(VAO)
    GLuint VAO = 0;
    glGenVertexArrays(1, &VAO); //generate the VAO
    glBindVertexArray(VAO); //bind the VAO
    glEnableVertexAttribArray(0); //enable vertex attributes
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &this->position, NULL);
    glCompileShader(vertexShader);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &this->color, NULL);
    glCompileShader(fragmentShader);
    this->shader = glCreateProgram();
    glAttachShader(this->shader, fragmentShader);
    glAttachShader(this->shader, vertexShader);
    glLinkProgram(this->shader);

    return this;
}
unsigned int AShape::getShader()
{
    return this->shader;
}
const char* AShape::getPosition() {
    return this->position;
}

const char* AShape::getColor() {
    return this->position;
}