set(SOURCES
	test_vector.cpp
)

add_executable(test_vector ${SOURCES})
target_link_libraries(test_vector
	gtest_main
	vector_lib
)

add_test(test_vector test_vector)