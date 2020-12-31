
target_include_directories(MOSP BEFORE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(BulletCollision)
add_subdirectory(BulletDynamics)
add_subdirectory(LinearMath)
