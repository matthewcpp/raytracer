#include "image_writer.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBI_MSC_SECURE_CRT
#include "stb_image_write.h"

#include <cmath>
#include <vector>

namespace raytracer
{

struct ImagePixel
{
	uint8_t r, g, b, a;

	ImagePixel(const glm::vec4& fpixel);
};

ImagePixel::ImagePixel(const glm::vec4& fpixel)
{
	r = static_cast<uint8_t>(std::lround(fpixel.r * 255.0f));
	g = static_cast<uint8_t>(std::lround(fpixel.g * 255.0f));
	b = static_cast<uint8_t>(std::lround(fpixel.b * 255.0f));
	a = static_cast<uint8_t>(std::lround(fpixel.a * 255.0f));
}

bool ImageWriter::writeToFile(const std::string& path, Format format)
{
	if (!renderer_) {
		return false;
	}


	auto& data = renderer_->data();
	glm::ivec2 size(renderer_->size());

	std::vector<ImagePixel> image_pixels;
	image_pixels.reserve(data.size());

	for (size_t i = 0; i < data.size(); i++) {
		image_pixels.emplace_back(data[i]);
	}

	int result = stbi_write_png(path.c_str(), static_cast<int>(size.x), static_cast<int>(size.y), 4, image_pixels.data(), size.x * 4);

	return result != 0;
}

}
