cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

SET(OpenCV_DIR /home/complubot/Documents/POLLOTRON/CODE/opencv/installation/OpenCV-master/lib/cmake/opencv4)

project(img_loader)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(img_loader img_loader.cc)
target_link_libraries(img_loader ${OpenCV_LIBS})
