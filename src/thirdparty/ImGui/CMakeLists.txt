
set(SOURCES
    imconfig.h
    imgui.h
    imgui.cpp
    imgui_demo.cpp
    imgui_draw.cpp
    imgui_internal.h
    imgui_widgets.cpp
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h)

list(TRANSFORM SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

target_sources(MOSP PRIVATE ${SOURCES})

target_include_directories(MOSP BEFORE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(misc)
