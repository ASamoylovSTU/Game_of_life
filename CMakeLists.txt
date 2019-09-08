cmake_minimum_required (VERSION 2.8)
project (Game_of_life)
set (CMAKE_CXX_STANDARD 11)

include_directories(./include)
add_subdirectory (src)

enable_testing ()
add_subdirectory (tests)

find_package(Boost COMPONENTS chrono REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} GOL_lib ${Boost_LIBRARIES})
