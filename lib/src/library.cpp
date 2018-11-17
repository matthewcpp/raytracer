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

}
