#pragma once

#include "ray.h"
#include "raycast_result.h"
#include "material.h"

#include <glm/glm.hpp>

#include <memory>

namespace raytracer
{

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
	
	void setMaterial(std::unique_ptr<Material> material) { material_ = std::move(material); }
	Material* material() const { return material_.get(); }

protected:
	std::unique_ptr<Material> material_;
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