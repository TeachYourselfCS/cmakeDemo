cmake_minimum_required(VERSION 3.22)

find_package(CURL REQUIRED)
if(!CURL_FOUND)
    message(FATEL_ERROR: "Could not found the curl library")
endif()

add_library(answer STATIC answer.cpp )
message(STATUS "Current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(answer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(answer PRIVATE CURL::libcurl)
