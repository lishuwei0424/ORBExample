cmake_minimum_required(VERSION 2.8)
project(FastExample)

set(CMAKE_CXX_STANDARD 14)

#设置可执行文件的输出目录
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)

#opencv库 包含头文件目录
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(FastExample main.cpp)
target_link_libraries(FastExample  ${OpenCV_LIBS})