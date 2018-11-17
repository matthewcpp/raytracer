#pragma once

#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

#include <string>
#pragma once

#include <vector>
#include <cstdint>

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
	glm::uvec2 size() const { return size_; }

	/** 
	Returns a reference to the data buffer for this renderer.
	The two dimensional buffer is organized into a single array of pixels.  
	The top left pixel of the image (0,0) is the first item in the array.
	*/
	const std::vector<glm::vec4>& data() const { return data_; }

private:
	std::string name_;
	glm::uvec2 size_;

	std::vector<glm::vec4> data_;
};

}
