cmake_minimum_required(VERSION 3.0)

project(linux_opencv)

find_package(OpenCV REQUIRED)

add_executable(disparty_filter disparty_filtering.cpp)
target_link_libraries (disparty_filter ${OpenCV_LIBRARIES})
