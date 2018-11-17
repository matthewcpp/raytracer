#include <gtest/gtest.h>

#include "library.h"

TEST(Library, CreateRenderer)
{
	raytracer::Library library;

	std::string expected_name = "renderer";

	auto renderer = library.createRenderer(expected_name);

	ASSERT_NE(renderer, nullptr);
	ASSERT_EQ(renderer->name(), expected_name);
}

TEST(Library, CreateRendererSameName)
{
	raytracer::Library library;

	std::string name = "renderer";

	auto renderer1 = library.createRenderer(name);
	auto renderer2 = library.createRenderer(name);

	ASSERT_NE(renderer1, nullptr);
	ASSERT_EQ(renderer2, nullptr);
}

TEST(Library, GetRenderer)
{
	raytracer::Library library;

	std::string expected_name = "renderer";

	auto expected_renderer = library.createRenderer(expected_name);
	auto actual_renderer = library.getRenderer(expected_name);
	auto expected_null = library.getRenderer("bogus");

	ASSERT_NE(actual_renderer, nullptr);
	ASSERT_EQ(actual_renderer->name(), expected_name);

	ASSERT_EQ(expected_null, nullptr);
}