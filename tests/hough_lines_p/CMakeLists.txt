set (target hough_lines_p)

cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
project( ${target} )

if(APPLE)
find_package(OpenCV REQUIRED)
else()
find_package(OpenCV REQUIRED PATHS /home/complubot/Documents/POLLOTRON/CODE/opencv/installation/OpenCV-master NO_DEFAULT_PATH)
endif()

include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( ${target} ${target}.cc )
target_link_libraries( ${target} ${OpenCV_LIBS} )
