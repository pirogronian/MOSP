
set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)

add_executable(MOSP)

target_include_directories(MOSP BEFORE PUBLIC /opt/imgui)
target_include_directories(MOSP BEFORE PUBLIC ../thirdparty/bullet3/src)

add_definitions(-DBT_USE_DOUBLE_PRECISION)

add_subdirectory(thirdparty)

target_sources(MOSP PRIVATE
    Bullet.h
    CameraManipulator.h
    Math.h
    MospApplication.cpp
    RigidBody.h
    RigidBody.cpp
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
    Magnum::Primitives
    #Bullet::Dynamics
    )

# Make the executable a default target to build & run in Visual Studio
set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MospApplication)
