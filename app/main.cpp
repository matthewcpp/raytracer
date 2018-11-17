#include "library.h"
#include "image_writer.h"

int main(int argc, char ** argv)
{
	raytracer::Library library;
	auto renderer = library.createRenderer("main");
	renderer->render();

	raytracer::ImageWriter image_writer(renderer);

	image_writer.writeToFile("C:/temp/image.png", raytracer::ImageWriter::Format::png);

	return 0;
}