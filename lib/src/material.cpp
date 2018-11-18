#include "material.h"

#include "util.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/norm.hpp>

namespace raytracer
{

bool Diffuse::scatter(const Ray& ray_in, const RaycastResult& raycast_result, glm::vec3& attenuation, Ray& bounce) const
{
	bounce.origin = raycast_result.position;
	bounce.direction = glm::normalize(raycast_result.normal + util::randomPointInUnitSphere());
	attenuation = albedo_;

	return true;
}

}