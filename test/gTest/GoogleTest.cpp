#include "QuaterByteAdress.hpp"
#include <gtest/gtest.h>

TEST(test_01, basic_test_set)
{
	ASSERT_TRUE(versionPatch() > 0);
	ASSERT_TRUE(versionMin() >= 0);
	ASSERT_TRUE(versionMaj() >= 0);
}


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}