cmake_minimum_required(VERSION 3.18.4)

project(Test)

set(SOURCES test.cpp ../src/EnvelopeFollower.cpp)
find_package(iir REQUIRED)


add_executable(test ${SOURCES})

target_link_libraries(test gtest pthread iir::iir)
