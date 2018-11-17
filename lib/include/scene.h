#pragma once

#include "object.h"


#include <glm/glm.hpp>

#include <string>
#include <unordered_map>

namespace raytracer
{

class Scene
{
public:
	Scene(const std::string& name) : name_(name) {}

public:
	std::string name() const { return name_; }
	Sphere* addSphere(const std::string& name, const glm::vec3& center, float radius);

	bool raycast(const Ray& ray, float t_min, float t_max, RaycastResult& raycast_result);

private:
	std::string name_;
	std::unordered_map<std::string, std::unique_ptr<Object>> objects_;
};

}