#include "library.h"
#include "image_writer.h"
#include "material.h"

int main(int argc, char ** argv)
{
	raytracer::Library library;

	auto scene = library.createScene("main");
	auto spehere1 = scene->addSphere("sphere01", glm::vec3(0.0f, 0.0f, -1.0f), 0.5f);
	spehere1->setMaterial(std::make_unique<raytracer::Diffuse>(glm::vec3(0.5f, 0.5f, 0.5f)));

	auto spehere2 = scene->addSphere("sphere02", glm::vec3(0.0f, -100.5f, -1.0f), 100.0f);
	spehere2->setMaterial(std::make_unique<raytracer::Diffuse>(glm::vec3(0.5f, 0.5f, 0.5f)));

	auto renderer = library.createRenderer("main");
	renderer->setAntialiasSampleCount(10);
	renderer->setSize(glm::uvec2(200, 100));
	renderer->camera().height = 2.0;
	renderer->camera().width = 4.0;
	renderer->setScene(scene);

	renderer->render();

	raytracer::ImageWriter image_writer(renderer);

	image_writer.writeToFile("C:/temp/image.png", raytracer::ImageWriter::Format::png);

	return 0;
}