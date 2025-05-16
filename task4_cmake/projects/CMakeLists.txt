cmake_minimum_required(VERSION 3.2...3.27.5)

project(AllMyProjects)

enable_testing()
add_subdirectory(lib/googletest)

# исходники проекта
add_subdirectory(bubble_sort)
add_subdirectory(obuchaika)
add_subdirectory(LongNumbers)
add_subdirectory(doubly_linked_list)
add_subdirectory(vector)
