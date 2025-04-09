cmake_minimum_required(VERSION 3.2...3.27.5)
project(BubbleSort)

# Исходники
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CPP_DIR ${SRC_DIR}/cpp)
set(HPP_DIR ${SRC_DIR}/hpp)

add_executable(bubble_sort
    ${SRC_DIR}/main.cpp
    ${CPP_DIR}/io.cpp
    ${CPP_DIR}/sortings.cpp
)

target_include_directories(bubble_sort PRIVATE ${HPP_DIR})

# Подключаем тесты
# enable_testing()
# add_subdirectory(tests)
