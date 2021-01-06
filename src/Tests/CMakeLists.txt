
add_executable(AutoIndexTest AutoIndexTest.cpp)

target_include_directories(AutoIndexTest BEFORE PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")

target_link_libraries(AutoIndexTest Corrade::Utility)

add_executable(NonOwningLinkedListTest NonOwningLinkedListTest.cpp)

target_include_directories(NonOwningLinkedListTest BEFORE PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")

target_link_libraries(NonOwningLinkedListTest Corrade::Utility)
