project(bubble_sort_tests)

add_executable(test1
    test1.cpp
)

target_link_libraries(test1
    bubble_sort_lib
    gtest_main
)

add_test(TESTS test1)
