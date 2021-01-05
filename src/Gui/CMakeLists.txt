
set(SOURCES
    Gui.h
    Gui.cpp
    SceneGraph.h
    SceneGraph.cpp
    TransformInfo.h
    TransformInfo.cpp)

list(TRANSFORM SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

target_sources(MOSP PRIVATE ${SOURCES})
