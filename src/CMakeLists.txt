
set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)

add_executable(MOSP
    CameraManipulator.h
    Math.h
    MospApplication.cpp
    SceneGraph.h
    SceneGraph.cpp
    Simulation.h
    Simulation.cpp
    ViewportRotation.h
    ViewportRotation.cpp)

# Make the executable a default target to build & run in Visual Studio
set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MospApplication)
