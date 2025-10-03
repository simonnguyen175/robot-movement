cmake_minimum_required(VERSION 3.10)

# Project name and language
project(RobotMove LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    main.cpp
    grid.cpp
    robot.cpp
    command.cpp
)

# Build executable
add_executable(robot ${SOURCES})