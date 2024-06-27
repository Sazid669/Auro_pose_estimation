cmake_minimum_required(VERSION 3.1)
project(example)

set (CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)

include_directories(${OPENCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${OpenCV_LIBRARY_DIRS})

set(example_src
    src/main.cpp
   )
add_executable(example ${example_src})
target_link_libraries(example
    ${OpenCV_LIBRARIES}
    )

target_compile_options(example
    PRIVATE -O3 -std=c++11
    )
