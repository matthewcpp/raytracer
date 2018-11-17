set (app_sources
	main.cpp
)

add_executable(raytracer ${app_sources})

target_link_libraries(raytracer 
	libraytracer
	CONAN_PKG::sdl2
)
