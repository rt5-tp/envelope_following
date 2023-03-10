cmake_minimum_required(VERSION 3.8.0)

cmake_minimum_required(VERSION 3.5)

project(iir_example)

set(CMAKE_CXX_STANDARD 11)

find_package(iir REQUIRED)

add_executable(iir_example envelope_follower.cpp)

target_link_libraries(iir_example iir::iir)

target_compile_definitions(iir_example PRIVATE)