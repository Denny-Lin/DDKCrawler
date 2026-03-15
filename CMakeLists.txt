cmake_minimum_required(VERSION 3.10)

project(DDKCrawler)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

find_package(CURL REQUIRED)

file(GLOB SOURCES
    src/main.cpp
    src/core/*.cpp
)

add_executable(ddkcrawler ${SOURCES})

target_link_libraries(ddkcrawler CURL::libcurl)