project(Long_number_test)

add_executable(test2
    test2.cpp
)

target_link_libraries(test2
    long_number_lib
)

# add_test(TESTS test2)
