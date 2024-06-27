cmake_minimum_required(VERSION 3.1)
project(ArucoPose)

set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)

include_directories(${OPENCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${OpenCV_LIBRARY_DIRS})

set(ArucoPose pose.cpp)

add_executable(ArucoPose ${ArucoPose})
target_link_libraries(ArucoPose ${OpenCV_LIBRARIES})

target_compile_options(ArucoPose PRIVATE -O3 -std=c++11 )
