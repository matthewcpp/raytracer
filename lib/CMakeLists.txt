set (library_include
    include/camera.h
    include/image_writer.h
	include/library.h
    include/object.h
    include/ray.h
    include/renderer.h
    include/scene.h
)

set (library_src
    src/image_writer.cpp
	src/library.cpp
    src/object.cpp
    src/renderer.cpp
    src/scene.cpp
)

add_library(libraytracer ${library_include} ${library_src})

target_include_directories(libraytracer PUBLIC include)

target_link_libraries(libraytracer 
	CONAN_PKG::glm
	CONAN_PKG::yaml-cpp
	CONAN_PKG::stb
)
