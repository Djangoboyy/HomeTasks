#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

using gra::DoublyLinkedList;

TEST(DoublyLinkedListTests, DefaultConstructor) {
	DoublyLinkedList<int> list;
	EXPECT_EQ(list.get_size(), 0);
	EXPECT_FALSE(list.has_item(1));
}

TEST(DoublyLinkedListTests, PushBack) {
	DoublyLinkedList<int> list;
	for (int i = 0; i < 100; ++i) {
		list.push_back(i);
		EXPECT_TRUE(list.has_item(i));
	}
	EXPECT_EQ(list.get_size(), 100);
	EXPECT_FALSE(list.has_item(-1));
	EXPECT_FALSE(list.has_item(101));
}

TEST(DoublyLinkedListTests, RemoveFirst) {
	DoublyLinkedList<int> list;
	for (int i = 0; i < 10; ++i) {
		list.push_back(i);
	}
	list.remove_first(0);
	EXPECT_EQ(list.get_size(), 9);
	EXPECT_FALSE(list.remove_first(0));
	EXPECT_FALSE(list.has_item(0));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
