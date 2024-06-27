cmake_minimum_required(VERSION 3.1)
project(calibration)

set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)

include_directories(${OPENCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${OpenCV_LIBRARY_DIRS})

set(calibration_src calibration.cpp)

add_executable(calibration ${calibration_src})
target_link_libraries(calibration ${OpenCV_LIBRARIES})

target_compile_options(calibration PRIVATE -O3 -std=c++11 )

