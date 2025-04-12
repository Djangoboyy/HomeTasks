cmake_minimum_required(VERSION 3.2...3.27.5)

project(AllMyProjects)

# объявление библиотек и их путей
# =
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# [googletest]

# На случай, если не найдется, но его из=за реализации просто не может быть
# set(googletest ${LIB_PATH}/googletest)
# set(CMAKE_PREFIX_PATH "${googletest}" CACHE PATH "Ищем GoogleTest с помощью find_package")
find_package(GTest REQUIRED)

# =


# исходники проекта
add_subdirectory(bubble_sort)
add_subdirectory(obuchaika)
# add_subdirectory(tests)
