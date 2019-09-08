find_package(OpenCV REQUIRED )

include_directories(${OpenCV_INCLUDE_DIRS})

add_library (GOL_lib Engine.cpp Visualizer.cpp)

target_link_libraries( GOL_lib ${OpenCV_LIBS} )
