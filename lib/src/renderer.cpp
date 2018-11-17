#include "renderer.h"

#include <iostream>

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
	glm::vec2 f_size(size_);

	for (size_t j = 0; j < size_.y; j++) {
		for (size_t i = 0; i < size_.x; i++) {
			glm::vec4 pixel(float(i) / f_size.x, float(j) / f_size.y, 0.2f, 1.0f);
			
			size_t index = j * size_.x + i;

			if (index > data_.size()) {
				std::cout << "index: " << index << " size: " << data_.size() << " i: " << i << " j: " << j << std::endl;
			}
			data_[index] = pixel;
		}
	}

	return true;
}

}