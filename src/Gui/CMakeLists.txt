
set(SOURCES
    SceneGraph.h
    SceneGraph.cpp)

list(TRANSFORM SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

target_sources(MOSP PRIVATE ${SOURCES})
