
add_executable(AutoIndexTest AutoIndexTest.cpp)

target_include_directories(AutoIndexTest BEFORE PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")

target_link_libraries(AutoIndexTest Corrade::Utility)

add_executable(NonOwningLinkedListTest NonOwningLinkedListTest.cpp)

target_include_directories(NonOwningLinkedListTest BEFORE PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")

target_link_libraries(NonOwningLinkedListTest Corrade::Utility)

add_executable(AccumulatorTest AccumulatorTest.cpp)
target_include_directories(AccumulatorTest BEFORE PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")
target_link_libraries(AccumulatorTest
    Corrade::Utility
    Corrade::Interconnect
    Magnum::Magnum
    MospUtils)

add_executable(PointerTest PointerTest.cpp)
target_link_libraries(PointerTest Corrade::Containers Corrade::Utility)

add_executable(IndexEntryTest IndexEntryTest.cpp)
target_include_directories(IndexEntryTest BEFORE PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")
