cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

SET(OpenCV_DIR /home/complubot/Documents/POLLOTRON/CODE/opencv/installation/OpenCV-master/lib/cmake/opencv4)
set(target shapes)

project(${target})
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(${target} ${target}.cc)
target_link_libraries(${target} ${OpenCV_LIBS})
