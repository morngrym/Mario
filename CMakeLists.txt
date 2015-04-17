cmake_minimum_required(VERSION 2.8)

# Set project name
project(Mario)

# Make the build debug
set(CMAKE_CXX_FLAGS_DEBUG .)

set(CMAKE_CXX_FLAGS "-std=c++11")

# Set the version in a config.h file
set(Mario_VERSION_MAJOR 0)
set(Mario_VERSION_MINOR 1)

# Find all source files
aux_source_directory(. SRC_LIST)
aux_source_directory(./Game SRC_LIST)
aux_source_directory(./Game/Core SRC_LIST)

# Define sources and executable
set(EXECUTABLE_NAME "Mario")
add_executable(${PROJECT_NAME} ${SRC_LIST})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Find any version 2.x of SFML
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
