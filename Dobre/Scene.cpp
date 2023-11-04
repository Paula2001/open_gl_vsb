#include "Scene.h"

Scene::Scene() {
}

Scene::~Scene() {
}

void Scene::render() {
    Model x(-0.5f);
    Model y(-1.5f);
    
    Shader shader("#version 330\n"
        "layout(location=0) in vec3 vp;"
        "void main () {"
        "     gl_Position = vec4(vp, 2.0);"
        "}",
        "#version 330\n"
        "out vec4 frag_colour;"
        "void main () {"
        "     frag_colour = vec4(0.0, 1.0, 0.0, 1.0);"
        "}");
    shader.use();
    x.draw();

    Shader xxx("#version 330\n"
        "layout(location=0) in vec3 vp;"
        "void main () {"
        "     gl_Position = vec4(vp, 1.8);"
        "}",
        "#version 330\n"
        "out vec4 frag_colour;"
        "void main () {"
        "     frag_colour = vec4(1.0, 0.0, 0.0, 1.0);"
        "}");
    xxx.use();
    y.draw();
}
