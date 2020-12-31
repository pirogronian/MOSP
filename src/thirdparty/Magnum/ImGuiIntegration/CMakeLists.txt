
set(SOURCES
    Context.cpp
    Context.h
    Context.hpp
    Integration.h
    Widgets.h

    visibility.h)

list(TRANSFORM SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

target_sources(MOSP PRIVATE ${SOURCES})

target_include_directories(MOSP BEFORE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
