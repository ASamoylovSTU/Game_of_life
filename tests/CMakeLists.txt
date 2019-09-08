find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
include_directories (${PROJECT_SOURCE_DIR}/include)

add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable(Game_of_life_test Engine_test.cpp)

target_link_libraries(Game_of_life_test ${Boost_LIBRARIES} GOL_lib)

add_test(NAME Game_of_life_test COMMAND Game_of_life_test)
