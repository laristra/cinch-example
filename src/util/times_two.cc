#include <gtest/gtest.h>
#include "upart.h"

TEST(times_two, two_times_two) {
	EXPECT_EQ(4.0, util::times_two(2.0));
}
