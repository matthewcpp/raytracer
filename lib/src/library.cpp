#include "library.h"

#include <yaml-cpp/yaml.h>


namespace raytracer
{


Renderer* Library::createRenderer(const std::string& name)
{
	auto result = renderers_.find(name);
	if (result == renderers_.end()) {
		renderers_[name] = std::make_unique<Renderer>(name);

		return renderers_[name].get();
	}
	else {
		return nullptr;
	}
}

Renderer* Library::getRenderer(const std::string& name)
{
	auto result = renderers_.find(name);
	if (result == renderers_.end()) {
		return nullptr;
	}
	else {
		return result->second.get();
	}
}

Scene* Library::createScene(const std::string& name)
{
	auto result = scenes_.find(name);
	if (result == scenes_.end()) {
		scenes_[name] = std::make_unique<Scene>(name);

		return scenes_[name].get();
	}
	else {
		return nullptr;
	}
}

Scene* Library::getScene(const std::string& name)
{
	auto result = scenes_.find(name);
	if (scenes_.find(name) == scenes_.end()) {
		return nullptr;
	}
	else {
		return result->second.get();
	}
}

}
