cmake_minimum_required(VERSION 3.1)
project(OpenCVTest)
# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
find_package(OpenCV REQUIRED)
add_executable(OpenCVTest openCVTest.cpp)
target_link_libraries(OpenCVTest ${OpenCV_LIBS})
