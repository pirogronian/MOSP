cmake_minimum_required(VERSION 3.4)
project(MOSP)

cmake_policy(SET CMP0079 NEW)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})

set(WITH_IMGUI ON CACHE BOOL "" FORCE)
set(WITH_BULLET ON CACHE BOOL "" FORCE)

#set(ImGui_INCLUDE_DIR /opt/imgui)

find_package(Magnum REQUIRED GL Sdl2Application SceneGraph Shaders Primitives)
find_package(MagnumPlugins REQUIRED)

# Disable Bullet tests and demos
set(BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
set(BUILD_BULLET2_DEMOS OFF CACHE BOOL "" FORCE)
set(BUILD_CPU_DEMOS OFF CACHE BOOL "" FORCE)
set(BUILD_OPENGL3_DEMOS OFF CACHE BOOL "" FORCE)
# While not needed for Magnum, you might actually want some of those
set(BUILD_ENET OFF CACHE BOOL "" FORCE)
set(BUILD_CLSOCKET OFF CACHE BOOL "" FORCE)
set(BUILD_EXTRAS OFF CACHE BOOL "" FORCE)
set(BUILD_BULLET3 OFF CACHE BOOL "" FORCE)
# This is needed in case BUILD_EXTRAS is enabled, as you'd get a CMake syntax
# error otherwise
set(PKGCONFIG_INSTALL_PREFIX "lib${LIB_SUFFIX}/pkgconfig/")
# Bullet's buildsystem doesn't correctly express dependencies between static
# libs, causing linker errors on Magnum side. If you have CMake 3.13, the Find
# module is able to correct that on its own, otherwise you need to enable
# BUILD_SHARED_LIBS to build as shared.
#set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
set(USE_DOUBLE_PRECISION ON CACHE BOOL "" FORCE)
add_subdirectory(thirdparty/bullet3 EXCLUDE_FROM_ALL)

find_package(Bullet REQUIRED Dynamics NO_DEFAULT_PATH PATHS thirdparty/bullet3)
#find_package(Bullet REQUIRED Dynamics)

message(${BULLET_FOUND})
message("${BULLET_VERSION}")
message("${BULLET_INCLUDE_DIRS}")
message("${BULLET_INCLUDE_DIR}")
message("${BULLET_LIBRARIES}")
message("${BULLET_LIBRARY}")

message(${Bullet_FOUND})
message("${Bullet_VERSION}")
message("${Bullet_INCLUDE_DIRS}")
message("${Bullet_INCLUDE_DIR}")
message("${Bullet_LIBRARIES}")
message("${Bullet_LIBRARY}")

include_directories("thirdparty/bullet3/src")

find_package(MagnumIntegration REQUIRED ImGui Bullet)

#set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

target_link_libraries(MOSP PRIVATE
    Magnum::Application
    Magnum::GL
    Magnum::Magnum
    Magnum::SceneGraph
    Magnum::Shaders
    Magnum::Primitives
    MagnumIntegration::ImGui
    MagnumIntegration::Bullet
    Bullet::Dynamics
    )
