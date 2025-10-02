cmake_minimum_required(VERSION 4.0)

project(deep_copy_ptr CXX)

include(CTest)

set(CMAKE_CXX_STANDARD 23)

add_library(
    ${PROJECT_NAME}
INTERFACE
    define/deep_copy_ptr.hpp
)

target_include_directories(
    ${PROJECT_NAME}
INTERFACE
    define
)

add_executable(test_${PROJECT_NAME} test/test_deep_copy_ptr.cpp)

add_test(NAME sample_run COMMAND test_${PROJECT_NAME})

target_link_libraries(
    test_${PROJECT_NAME}
PRIVATE
    ${PROJECT_NAME}
)
