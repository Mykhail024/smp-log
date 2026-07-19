add_executable(01_basic ${CMAKE_CURRENT_SOURCE_DIR}/01_basic.cpp)
target_link_libraries(01_basic PRIVATE smp::log)

add_executable(02_levels ${CMAKE_CURRENT_SOURCE_DIR}/02_levels.cpp)
target_link_libraries(02_levels PRIVATE smp::log)

add_executable(03_fatal_policy ${CMAKE_CURRENT_SOURCE_DIR}/03_fatal_policy.cpp)
target_link_libraries(03_fatal_policy PRIVATE smp::log)

