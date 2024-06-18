cmake_minimum_required(VERSION 3.14)

set_source_files_properties(filename.c PROPERTIES LANGUAGE CXX)

project(ToMakeDesktop)

# Add subdirectories for dependencies
add_subdirectory(dependencies/glfw)

# Collect all .c files from the leif source directory
file(GLOB LEIF_SOURCES dependencies/leif/leif.c)
file(GLOB GLAD_SOURCES dependencies/glad/glad.c)
file(GLOB CLIPBOARD_SOURCES dependencies/libclipboard/src/*.c)


# Add executable, including leif source files
add_executable(${PROJECT_NAME} main.c ${LEIF_SOURCES} ${GLAD_SOURCES} ${CLIPBOARD_SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC dependencies/libclipboard/include)
target_include_directories(${PROJECT_NAME} PUBLIC dependencies/glfw/include)
target_include_directories(${PROJECT_NAME} PUBLIC dependencies/leif/include)
target_include_directories(${PROJECT_NAME} PUBLIC dependencies/cglm/include)
target_include_directories(${PROJECT_NAME} PUBLIC dependencies/stb_image)
target_include_directories(${PROJECT_NAME} PUBLIC dependencies/glad)


# Link against GLFW and other necessary libraries
target_link_libraries(${PROJECT_NAME} PUBLIC glfw opengl32 gdi32)
