cmake_minimum_required(VERSION 3.4)
project(MOSP)

cmake_policy(SET CMP0079 NEW)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})

find_package(Corrade REQUIRED Utility Interconnect)
find_package(Magnum REQUIRED GL Sdl2Application SceneGraph Shaders Primitives)
find_package(MagnumPlugins REQUIRED)

if(MSVC)
    #string(REGEX REPLACE "/W[1-3]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
    add_compile_options(-w)
endif()

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

