
set(SOURCES
    Accumulator.h
    Accumulator.cpp
    AutoIndexer.h
    NonOwningLinkedList.h)

add_library(Utils STATIC ${SOURCES})

#list(TRANSFORM SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

#target_sources(MOSP PRIVATE ${SOURCES})
