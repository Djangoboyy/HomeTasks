project(Long_Number_sort_module)

add_library(long_number_lib STATIC long_number.cpp)

target_include_directories(long_number_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
