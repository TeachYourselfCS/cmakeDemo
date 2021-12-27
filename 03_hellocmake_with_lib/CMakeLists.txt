cmake_minimum_required(VERSION 3.22)
project(answerApp)

add_subdirectory(answer)
add_executable(answerApp main.cpp)
target_link_libraries(answerApp  answer)
