#pragma once

#include "glm/vec3.hpp"

namespace raytracer
{

struct Camera
{
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	float width = 4.0f;
	float height = 2.0f;
};

}

