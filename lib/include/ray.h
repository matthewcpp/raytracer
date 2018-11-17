#pragma once

#include "glm/glm.hpp"

namespace raytracer
{

struct Ray
{
	Ray() = default;
	Ray(const glm::vec3& orig, const glm::vec3 dir) : origin(orig), direction(dir) {}

	glm::vec3 origin;
	glm::vec3 direction;
};

}