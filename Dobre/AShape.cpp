#include "AShape.h"
#include "StringMan.h"

AShape* AShape::setColor(char color) {
    const char* fragment_shader = "#version 330\n"
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
        r = "frag_colour = vec4(1.0, 0.0, 0.0, 1.0)";
        StringMan::replace(needle, r, fragment_shader);
        break;
    case 'g':
        g = "frag_colour = vec4(0.0, 1.0, 0.0, 1.0)";
        this->color = StringMan::replace(needle, g, fragment_shader);
        break;
    case 'b':
        b = "frag_colour = vec4(0.0, 0.0, 1.0, 1.0);";
        this->color = StringMan::replace(needle, b, fragment_shader);
        break;
    case 'p':
        p = "frag_colour = vec4(1.0, 0.0, 1.0, 1.0)";
        this->color = StringMan::replace(needle, p, fragment_shader);
        break;
    default:
        w = "frag_colour = vec4(1.0, 1.0, 1.0, 1.0)";
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
const char* AShape::getPosition() {
    return this->position;
}

const char* AShape::getColor() {
    return this->position;
}