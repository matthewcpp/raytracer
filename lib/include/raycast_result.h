#pragma once

#include <glm/glm.hpp>

namespace raytracer
{

class Object;

struct RaycastResult
{
	const Object* object = nullptr;
	float t;
	glm::vec3 position;
	glm::vec3 normal;
};

}