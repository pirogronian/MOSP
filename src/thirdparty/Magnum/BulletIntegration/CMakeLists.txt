
set(SOURCES
    DebugDraw.cpp
    MotionState.cpp
    DebugDraw.h
    Integration.h
    MotionState.h
    visibility.h)

list(TRANSFORM SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

target_sources(MOSP PRIVATE ${SOURCES})

target_include_directories(MOSP BEFORE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
