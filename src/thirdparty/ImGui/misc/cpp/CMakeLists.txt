
set(SOURCES
    imgui_stdlib.cpp
    imgui_stdlib.h)

list(TRANSFORM SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

target_sources(MOSP PRIVATE ${SOURCES})

#target_include_directories(MOSP BEFORE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

