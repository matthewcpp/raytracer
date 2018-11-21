#include "object.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/intersect.hpp>

namespace raytracer
{

ObjectType Sphere::type() const
{
	return ObjectType::sphere;
}

bool Sphere::hit(const Ray& ray, float t_min, float t_max, RaycastResult& hit_result) const
{
	glm::vec3 hit_pos, hit_normal;

	bool glm_result = glm::intersectRaySphere(ray.origin, ray.direction, center, radius, hit_pos, hit_normal);
	if (glm_result) {
		hit_result.object = this;
		hit_result.position = hit_pos;
		hit_result.normal = hit_normal;

		hit_result.t = glm::distance(ray.origin, hit_pos);
		return hit_result.t >= t_min && hit_result.t <= t_max;
	}
		
	return false;
}

}