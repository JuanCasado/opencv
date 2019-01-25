cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
project( img_to_grayscale )

if(APPLE)
find_package(OpenCV REQUIRED)
else()
find_package(OpenCV REQUIRED PATHS /home/complubot/Documents/POLLOTRON/CODE/ope$
endif()

include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( img_to_grayscale img_to_grayscale.cc )
target_link_libraries( img_to_grayscale ${OpenCV_LIBS} )
