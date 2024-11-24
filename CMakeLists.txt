cmake_minimum_required(VERSION 3.0)
project(mymuduo)

# 最终编译为so动态库,设置动态库路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置调试信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

#定义参与编译的源代码文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

add_library(mymuduo SHARED ${SRC_LIST})

# test
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(test ${PROJECT_SOURCE_DIR}/testCode/main.cpp)
target_link_libraries(test mymuduo)