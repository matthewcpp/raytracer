#pragma once

#include "renderer.h"
#include "scene.h"

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
	@param unique name of the renderer to retrieve.
	@reutrns renderer with the given handle or null if no renderer was found.
	*/
	Renderer* getRenderer(const std::string& name);

	/**
	Creates a new Scene
	@param name unique name for this scene.
	@returns new scene object, or null if a scene already exists with the supplied name
	*/
	Scene* createScene(const std::string& name);

	/**
	Gets a handle to a created Scene
	@param unique name of the scene to retrieve.
	@reutrns scene with the given handle or null if no scene was found.
	*/
	Scene* getScene(const std::string& name);

private:
	std::unordered_map<std::string, std::unique_ptr<Renderer>> renderers_;
	std::unordered_map<std::string, std::unique_ptr<Scene>> scenes_;
};

}
