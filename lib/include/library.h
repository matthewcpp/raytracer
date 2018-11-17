#pragma once

#include "renderer.h"
#pragma once

#include "glm/vec3.hpp"

#include <string>
#include <unordered_map>
#include <memory>

namespace raytracer
{

class Library
{
public:

	/**
	Creates a new Renderer.
	@param name unique name for this renderer.
	@returns new renderer object, or null if a renderer already exists with the supplied name.
	*/
	Renderer* createRenderer(const std::string& name);

	/**
	Gets a handle to a created Renderer
	@param unique name for the renderer to retrieve.
	@reutrns renderer with the given handle or null if no renderer was found.
	*/
	Renderer* getRenderer(const std::string& name);

private:
	std::unordered_map<std::string, std::unique_ptr<Renderer>> renderers_;
};

}
