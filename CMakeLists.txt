project(raytracer)
cmake_minimum_required(VERSION 3.0)

include(build/conanbuildinfo_multi.cmake)
conan_basic_setup(TARGETS)

add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(app)
