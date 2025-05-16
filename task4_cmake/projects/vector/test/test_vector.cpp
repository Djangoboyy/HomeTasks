#include <gtest/gtest.h>
#include "vector.hpp"

using gra::Vector;

TEST(VectorTest, DefaultConstructor) {
	Vector<int> v;
	EXPECT_EQ(v.get_size(), 0);
}

TEST(VectorTest, PushBack) {
	Vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
		EXPECT_TRUE(v.has_item(i));
	}
	EXPECT_FALSE(v.has_item(-1));
	EXPECT_FALSE(v.has_item(10));
}

TEST(VectorTest, Insert) {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.insert(1, 3);
	EXPECT_EQ(v.get_size(), 3);
	EXPECT_TRUE(v.has_item(2));
	EXPECT_FALSE(v.has_item(4));
}

TEST(VectorTest, RemoveFirst) {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	EXPECT_EQ(v.get_size(), 4);
	EXPECT_TRUE(v.remove_first(1));
	EXPECT_EQ(v.get_size(), 3);
	EXPECT_FALSE(v.has_item(1));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
