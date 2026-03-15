cmake_minimum_required(VERSION 3.10)

project(DDKCrawler)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES
    src/main.cpp
    src/core/*.cpp
)

add_executable(ddkcrawler ${SOURCES})
