cmake_minimum_required(VERSION 3.13)

project(queue)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/inc/"
    "${CMAKE_CURRENT_SOURCE_DIR}/../LinkedList/inc"
    )

FILE(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})