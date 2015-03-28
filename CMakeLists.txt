project(Mario)
cmake_minimum_required(VERSION 2.8)

set(Mario_VERSION_MAJOR 0)
set(Mario_VERSION_MINOR 1)

aux_source_directory(. SRC_LIST)
aux_source_directory(./Game SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(CMAKE_CXX_FLAGS_DEBUG .)
