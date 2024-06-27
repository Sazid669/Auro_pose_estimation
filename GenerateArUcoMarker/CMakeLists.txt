cmake_minimum_required(VERSION 3.0)
project(GenerateArUcoMarker)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(generate_marker generate_marker.cpp)
target_link_libraries(generate_marker ${OpenCV_LIBS})
