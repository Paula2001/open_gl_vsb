#include "Triangle.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
Triangle::Triangle()
{
}

void Triangle::draw(GLFWwindow* window)
{
    GLuint VBO = 0;
    GLuint s = 3;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(this->getShader());
    glBindVertexArray(s);
    // draw triangles
    glDrawArrays(GL_TRIANGLES, 0, 3); //mode,first,count
    // update other events like input handling
    glfwPollEvents();
    // put the stuff we’ve been drawing onto the display
    glfwSwapBuffers(window);
}
