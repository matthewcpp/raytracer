#pragma once

#include "renderer.h"

#include <string>

namespace raytracer 
{

class ImageWriter
{
public:
	enum Format {
		png,
		jpeg
	};

public:
	ImageWriter() = default;
	ImageWriter(Renderer* renderer) : renderer_(renderer) {}

public:
	/**
	Writes the data in the renderer's buffer to an image file.
	@param path the file system path to write the image to.
	@param format the image file format to write.
	@returns boolean value indicating whether writing the file was successful.
	*/
	bool writeToFile(const std::string& path, Format format);

	/** Sets the renderer that will be used for image writing operations */
	void setRenderer(Renderer* renderer) { renderer_ = renderer; }

private:
	Renderer* renderer_ = nullptr;
};

}