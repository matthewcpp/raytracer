#pragma once

#include "ray.h"

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

enum ObjectType
{
	sphere
};

class Object
{
public:
	virtual ~Object() {}

	virtual ObjectType type() const = 0;
	virtual bool hit(const Ray& ray, float t_min, float t_max, RaycastResult& hit_result) const = 0;
};

class Sphere : public Object
{
public:
	Sphere(const glm::vec3& c, float r) : center(c), radius(r) {}

	glm::vec3 center;
	float radius;

	virtual ObjectType type() const override;
	virtual bool hit(const Ray& ray, float t_min, float t_max, RaycastResult& hit_result) const override;
};

}