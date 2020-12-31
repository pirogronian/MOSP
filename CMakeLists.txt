cmake_minimum_required(VERSION 3.4)
project(MOSP)

cmake_policy(SET CMP0079 NEW)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})

find_package(Magnum REQUIRED GL Sdl2Application SceneGraph Shaders Primitives)
find_package(MagnumPlugins REQUIRED)

add_subdirectory(src)

