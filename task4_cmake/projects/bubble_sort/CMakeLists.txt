cmake_minimum_required(VERSION 3.2...3.27.5)
project(bubble_sort)

# Исходники
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(BB_CPP_DIR ${SRC_DIR}/cpp CACHE PATH "Доступность к реализации cpp сортировки из других сестринских проектов/подпроектов")
set(BB_HPP_DIR ${SRC_DIR}/hpp CACHE PATH "Доступность к реализации hpp сортировки из других сестринских проектов/подпроектов")

add_library(bubble_sort_modules STATIC
    ${BB_CPP_DIR}/io.cpp
    ${BB_CPP_DIR}/sortings.cpp
)

target_include_directories(bubble_sort_modules PUBLIC ${BB_HPP_DIR})

add_executable(bubble_sort
    ${SRC_DIR}/main.cpp
)

target_link_libraries(bubble_sort PRIVATE bubble_sort_modules)
