// Name : Paula Gorge, Login : GOR0096
#ifndef APPLICATION_H
#define APPLICATION_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Scene.h"

class Application {
public:
    Application();
    ~Application();

    void run();

private:
    GLFWwindow* window;
    int width, height;
};

#endif // APPLICATION_H
