set(SOURCES
	test_doubly_linked_list.cpp
)

add_executable(test_doubly_linked_list ${SOURCES})
target_link_libraries(test_doubly_linked_list
	gtest_main
	doubly_linked_list_lib
)

add_test(test_doubly_linked_list test_doubly_linked_list)