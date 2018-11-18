#include "renderer.h"
#include "object.h"

#include <random>

namespace raytracer
{

const glm::uvec2 kDefaultSize(640, 480);

/** By default the buffer is fully transparent */
const glm::vec4 kDefaultColor(0.0f, 0.0f, 0.0f, 0.0f);

Renderer::Renderer(const std::string& name)
	: name_(name), size_(kDefaultSize)
{
	clear();
}

void Renderer::clear()
{
	data_.resize(size_.x * size_.y, kDefaultColor);
}

void Renderer::setSize(const glm::uvec2 size)
{
	size_ = size;
}

bool Renderer::render()
{
	if (!scene_) {
		return false;
	}

	// if anti-aliasing is off, we still need perform one sample
	uint32_t sample_count = std::max(antialias_sample_count_, 1U);

	glm::vec2 f_size(size_);
	glm::vec3 lower_left_corner(-camera_.width / 2.0f, -camera_.height / 2.0f, -1.0);

	glm::vec3 horizontal(camera_.width, 0.0f, 0.0f);
	glm::vec3 vertical(0.0f, camera_.height, 0.0f);

	for (int j = size_.y - 1; j >= 0; j--) {
		for (int i = 0; i < size_.x; i++) {
			int index = (size_.y - 1 - j) * size_.x + i;

			glm::vec4 final_color(0.0f);
			for (uint32_t s = 0; s < sample_count; s++){
				float u = (i + util::randomFloat()) / f_size.x;
				float v = (j + util::randomFloat()) / f_size.y;

				glm::vec3 ray_target = lower_left_corner + (u * horizontal) + (v * vertical);
				glm::vec3 ray_dir = glm::normalize(ray_target - camera_.position);

				Ray ray(camera_.position, ray_dir);
				final_color += colorForRay(ray, 0);
			}

			data_[index] = final_color / static_cast<float>(sample_count);
		}
	}

	return true;
}



glm::vec4 Renderer::colorForRay(const Ray& ray, int bounce_count)
{
	RaycastResult raycast_result;

	if (scene_->raycast(ray, 0.001f, std::numeric_limits<float>::max(), raycast_result)) {
		Ray bounce;
		glm::vec3 attenuation;

		if (bounce_count < 10 && raycast_result.object->material()->scatter(ray, raycast_result, attenuation, bounce)) {
			return glm::vec4(attenuation, 1.0f) * colorForRay(bounce, bounce_count + 1);
		}
		else {
			return glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
		}
	}
	else {
		float t = 0.5f * (ray.direction.y) + 1.0f;
		return (1.0f - t) * glm::vec4(1.0f, 1.0f, 1.0f, 1.0f) + t * glm::vec4(0.5f, 0.7f, 1.0f, 1.0f);
	}
}

}