set (target contours)

cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
project( ${target} )

if(APPLE)
find_package(OpenCV REQUIRED)
else()
find_package(OpenCV REQUIRED PATHS /home/complubot/Documents/POLLOTRON/CODE/ope$
endif()

include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( ${target} ${target}.cc )
target_link_libraries( ${target} ${OpenCV_LIBS} )
