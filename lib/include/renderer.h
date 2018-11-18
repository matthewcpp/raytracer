#pragma once

#include "camera.h"
#include "scene.h"
#include "util.h"

#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

#include <string>
#include <vector>
#include <cstdint>
#include <random>

namespace raytracer
{

class Renderer
{
public:
	Renderer(const std::string& name);

public:
	/**
	Sets the size of the rendering buffer.
	Note that this will clear out any image that is currently rendered in the buffer.
	@param size the new size of the rendering buffer.
	*/
	void setSize(const glm::uvec2 size);
	
	/**
	Sets the scene that will be rendered
	@param scene the scene to use for rendering.
	*/
	void setScene(Scene* scene) { scene_ = scene; }

	/** Sets the number of samples to use for antialiasing.  Setting this value to zero will disable antialiasing*/
	void setAntialiasSampleCount(uint32_t antialias_sample_count) { antialias_sample_count_ = antialias_sample_count_;}

	/**
	Clears out the image in the buffer.
	The entire buffer will be set to the default transparent color.
	*/
	void clear();

	/**
	Renders the scene into the buffer.
	@returns boolean value indicating if rendering was successful.  Calling this method with no scene set will cause this method to return false.
	*/
	bool render();

	/** Gets the name of this renderer. */
	std::string name() const { return name_; }

	/** Gets the dimensions of the renderer's buffer */
	glm::ivec2 size() const { return size_; }

	/** Gets the number of samples to use for antialiasing. */
	uint32_t antialias_sample_count() const { return antialias_sample_count_; }

	/** 
	Returns a reference to the data buffer for this renderer.
	The two dimensional buffer is organized into a single array of pixels.  
	The top left pixel of the image (0,0) is the first item in the array.
	*/
	const std::vector<glm::vec4>& data() const { return data_; }

	/** Gets the camera associated with this renderer. */
	Camera& camera() { return camera_;  }

	/** Gets the scene associated with this renderer. */
	Scene* scene() { return scene_; }

private:
	glm::vec4 colorForRay(const Ray& ray, int bounce_count);
	glm::vec3 randomPointInUnitSphere();

private:
	std::string name_;
	glm::ivec2 size_;
	uint32_t antialias_sample_count_ = 25;

	std::vector<glm::vec4> data_;
	Camera camera_;
	Scene* scene_ = nullptr;

	
};

}
