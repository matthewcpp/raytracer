#include "util.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/norm.hpp>

namespace raytracer { namespace util {

template <class T>
T makeSeededRandomEngine()
{
	std::random_device device;
	return T(device());
}

struct RNG
{
	std::mt19937 random_engine = makeSeededRandomEngine<std::mt19937>();
	std::uniform_real_distribution<float> distribution{ 0.0f, 1.0f };
};

float randomFloat()
{
	static RNG rng;
	return rng.distribution(rng.random_engine);
}

// Generates a random point in a unit sphere by first generating a point in the unit cube about the origin and rejecting points that are not in a sphere.
glm::vec3 randomPointInUnitSphere()
{
	glm::vec3 point;
	do {
		point = 2.0f * glm::vec3(util::randomFloat(), util::randomFloat(), util::randomFloat()) - glm::vec3(1.0f);
	} while (glm::length2(point) > 1.0f);

	return point;
}

}}
