#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
class AShape
{
	public:
		AShape* setColor(char color);
		AShape* setPostion();
		AShape* setShader();
		const char* getColor();
		const char* getPosition();
		virtual void draw(GLFWwindow* window) = 0;
		unsigned int getShader();

	private:
		const char* color;
		unsigned int shader;
		const char* position;
};

