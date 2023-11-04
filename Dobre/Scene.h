#ifndef SCENE_H
#define SCENE_H

#include "Model.h"
#include "Shader.h"
#include <glm/glm.hpp>

class Scene {
public:
    Scene();
    ~Scene();

    void render();

private:
    glm::mat4 projection;
    glm::mat4 view;
};

#endif // SCENE_H
