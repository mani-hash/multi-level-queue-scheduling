cmake_minimum_required(VERSION 3.10)
project(MultiLevelQueueApp)

# Include generated config.cmake
include(config.cmake)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# Include directories (headers)
include_directories(include)

# Collect all source files recursively from src
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Set output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../${BIN_DIRECTORY})

# Create executable from all sources
add_executable(${APP_NAME} ${SOURCES})