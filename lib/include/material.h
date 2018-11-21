#pragma once

#include "ray.h"
#include "raycast_result.h"

#include <glm/glm.hpp>

namespace raytracer
{

class Material
{
public:
	enum Type 
	{
		diffuse,
		metal
	};

	virtual bool scatter(const Ray& ray_in, const RaycastResult& raycast_result, glm::vec3& attenuation, Ray& bounce) const = 0;
	virtual Type type() const = 0;
};

class Diffuse : public Material
{
public:
	Diffuse(const glm::vec3& albedo) : albedo_(albedo) {}
	Diffuse() : albedo_(0.5f, 0.5f, 0.5f) {}

	void setAlbedo(const glm::vec3& albedo) { albedo_ = albedo; }
	glm::vec3 albedo() const { return albedo_; }

public:
	virtual bool scatter(const Ray& ray_in, const RaycastResult& raycast_result, glm::vec3& attenuation, Ray& bounce) const override;
	virtual Type type() const override { return Type::diffuse; }

private:
	glm::vec3 albedo_;
};

class Metal : public Material
{
public:
	Metal(const glm::vec3& albedo) : albedo_(albedo) {}
	Metal() : albedo_(0.5f, 0.5f, 0.5f) {}

	void setAlbedo(const glm::vec3& albedo) { albedo_ = albedo; }
	glm::vec3 albedo() const { return albedo_; }

public:
	virtual bool scatter(const Ray& ray_in, const RaycastResult& raycast_result, glm::vec3& attenuation, Ray& bounce) const override;
	virtual Type type() const override { return Type::metal; }

private:
	glm::vec3 albedo_;
};

}