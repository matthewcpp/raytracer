#include "object.h"

namespace raytracer
{

ObjectType Sphere::type() const
{
	return ObjectType::sphere;
}

bool Sphere::hit(const Ray& ray, float t_min, float t_max, RaycastResult& hit_result) const
{
	glm::vec3 oc = ray.origin - center;
	float a = glm::dot(ray.direction, ray.direction);
	float b = glm::dot(oc, ray.direction);
	float c = glm::dot(oc, oc) - radius * radius;
	float discriminant = b * b - a * c;

	if (discriminant > 0) {
		float temp = (-b - sqrt(b*b - a*c)) / a;
		if (temp < t_max && temp > t_min) {
			hit_result.object = this;
			hit_result.t = temp;
			hit_result.position = ray.origin + ray.direction * hit_result.t;
			hit_result.normal = (hit_result.position - center) / radius;

			return true;
		}

		temp = (-b + sqrt(b*b - a*c)) / a;
		if (temp < t_max && temp > t_min) {
			hit_result.object = this;
			hit_result.t = temp;
			hit_result.position = ray.origin + ray.direction * hit_result.t;
			hit_result.normal = (hit_result.position - center) / radius;

			return true;
		}
	}
		
	return false;
}

}