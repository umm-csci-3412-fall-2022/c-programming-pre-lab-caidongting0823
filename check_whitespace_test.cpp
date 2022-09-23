#include <gtest/gtest.h>

#include "check_whitespace.h"

TEST(strip, EmptyString) {
	const char* testStr = strip("");
	ASSERT_STREQ("", testStr);
}

TEST(strip, NoWhitespace) {
	const char* testStr = strip("frog");
	ASSERT_STREQ("frog", testStr);
	free((char*) testStr);
}

TEST(strip, WhitespaceOnFront) {
	const char* testStr = strip("   frog");
	ASSERT_STREQ("frog", testStr);
	free((char*) testStr);
}

TEST(strip, WhitespaceOnBack) {
	const char* testStr = strip("frog  ");
	ASSERT_STREQ("frog", testStr);
	free((char*) testStr);
}

TEST(strip, WhitespaceOnBothEnds) {
	const char* testStr = strip("  frog    ");
	ASSERT_STREQ("frog", testStr);
	free((char*) testStr);
}

TEST(is_clean, EmptyString) {
    ASSERT_TRUE(is_clean(""));
}

TEST(is_clean, NoWhitespace) {
    ASSERT_TRUE(is_clean("University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnFront) {
    ASSERT_FALSE(is_clean("   University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnBack) {
    ASSERT_FALSE(is_clean("University of Minnesota Morris  "));
}

TEST(is_clean, WhitespaceOnBothEnds) {
    ASSERT_FALSE(is_clean(" University of Minnesota Morris"    ));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
