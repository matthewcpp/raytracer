set (test_sources
    test_library.cpp
    test_renderer.cpp
)

add_executable(test_raytracer ${test_sources})

target_link_libraries(test_raytracer 
	libraytracer
	CONAN_PKG::gtest
)
