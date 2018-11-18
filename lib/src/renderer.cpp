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

glm::vec4 color(const glm::vec3& ray_origin, const glm::vec3& ray_dir)
{
	float t = 0.5f * (ray_dir.y) + 1.0f;
	return (1.0f - t) * glm::vec4(0.0f, 1.0f, 1.0f, 1.0f) + t * glm::vec4(0.5f, 0.7f, 1.0f, 1.0f);
}

bool Renderer::render()
{
	if (!scene_) {
		return false;
	}

	std::random_device random_device;
	std::mt19937 twister(random_device());
	std::uniform_real_distribution<> rand_real(0.0f, 1.0f);

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
				float u = (i + static_cast<float>(rand_real(twister))) / f_size.x;
				float v = (j + static_cast<float>(rand_real(twister))) / f_size.y;

				glm::vec3 ray_target = lower_left_corner + (u * horizontal) + (v * vertical);
				glm::vec3 ray_dir = glm::normalize(ray_target - camera_.position);

				Ray ray(camera_.position, ray_dir);
				RaycastResult raycast_result;

				if (scene_->raycast(ray, camera_.near, camera_.far, raycast_result)) {
					final_color += 0.5f * (glm::vec4(raycast_result.normal, 1.0f) + glm::vec4(1.0f));
				}
				else {
					final_color += color(camera_.position, ray_dir);
				}
			}

			data_[index] = final_color / static_cast<float>(sample_count);
		}
	}

	return true;
}

}