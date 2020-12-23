cmake_minimum_required(VERSION 3.4)
project(MOSP)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})

set(WITH_IMGUI ON CACHE BOOL "" FORCE)
set(WITH_BULLET ON CACHE BOOL "" FORCE)

set(ImGui_INCLUDE_DIR /opt/imgui)

find_package(Magnum REQUIRED GL Sdl2Application SceneGraph Shaders Primitives)
find_package(MagnumPlugins REQUIRED)
#find_package(MagnumIntegration REQUIRED ImGui Bullet)

#set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
