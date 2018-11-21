#include <gtest/gtest.h>

#include "library.h"

TEST(Renderer, WillNotRenderWithoutAScene)
{
	raytracer::Library library;
	auto renderer = library.createRenderer("test");
	bool result = renderer->render();

	ASSERT_FALSE(result);
}
