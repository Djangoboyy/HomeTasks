cmake_minimum_required(VERSION 3.2...3.27.5)
project(tests)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Исходники тестов
add_executable(tests
    ${SRC_DIR}/test1.cpp
)

target_include_directories(tests PRIVATE ${BB_HPP_DIR})

target_link_libraries(tests PRIVATE
    bubble_sort_modules
    GTest::gtest_main
)
