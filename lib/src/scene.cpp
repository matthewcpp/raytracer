#include "scene.h"

namespace raytracer
{

Sphere* Scene::addSphere(const std::string& name, const glm::vec3& center, float radius)
{
	auto object_result = objects_.find(name);

	if (object_result == objects_.end()) {
		objects_[name] = std::make_unique<Sphere>(center, radius);
		
		return static_cast<Sphere*>(objects_[name].get());
	}
	else {
		return nullptr;
	}
}

bool Scene::raycast(const Ray& ray, float t_min, float t_max, RaycastResult& raycast_result)
{
	RaycastResult obj_result;
	float hit_distance = t_max;

	for (const auto& object : objects_) {
		if (object.second->hit(ray, t_min, hit_distance, obj_result)) {
			hit_distance = obj_result.t;
			raycast_result = obj_result;
		}
	}
	return raycast_result.object != nullptr;
}

}