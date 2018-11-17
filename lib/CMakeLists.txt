set (library_include
    include/image_writer.h
	include/library.h
    include/renderer.h
)

set (library_src
    src/image_writer.cpp
	src/library.cpp
    src/renderer.cpp
)

add_library(libraytracer ${library_include} ${library_src})

target_include_directories(libraytracer PUBLIC include)

target_link_libraries(libraytracer 
	CONAN_PKG::glm
	CONAN_PKG::yaml-cpp
	CONAN_PKG::stb
)
