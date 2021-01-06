
set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)

add_executable(MOSP)

target_include_directories(MOSP SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-DBT_USE_DOUBLE_PRECISION)

add_subdirectory(thirdparty)
add_subdirectory(Utils)
add_subdirectory(Gui)
add_subdirectory(Tests)

target_sources(MOSP PRIVATE
    Bullet.h
    CameraManipulator.h
    Math.h
    Math.cpp
    MospApplication.cpp
    Object.cpp
    Object.h
    #RigidBody.h
    #RigidBody.cpp
    SceneGraph.h
    SceneGraph.cpp
    Simulation.h
    Simulation.cpp
    ViewportRotation.h
    ViewportRotation.cpp
)

target_link_libraries(MOSP PRIVATE
    Magnum::Application
    Magnum::GL
    Magnum::Magnum
    Magnum::SceneGraph
    Magnum::Shaders
    Magnum::Primitives)

# Make the executable a default target to build & run in Visual Studio
set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MospApplication)
