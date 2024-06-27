cmake_minimum_required(VERSION 3.0)
project(ArUcoDetector)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(detect_markers detect_markers.cpp)
target_link_libraries(detect_markers ${OpenCV_LIBS})
