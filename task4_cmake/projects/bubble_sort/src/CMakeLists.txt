project(bubble_sort_module)

add_library(bubble_sort_lib STATIC sortings.cpp)

target_include_directories(bubble_sort_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
