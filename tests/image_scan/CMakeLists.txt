cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
project( image_scan )

if(APPLE)
find_package(OpenCV REQUIRED)
else()
find_package(OpenCV REQUIRED PATHS /home/complubot/Documents/POLLOTRON/CODE/ope$
endif()

include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( image_scan image_scan.cc )
target_link_libraries( image_scan ${OpenCV_LIBS} )
