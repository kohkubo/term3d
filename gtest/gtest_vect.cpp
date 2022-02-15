#include <gtest/gtest.h>
#include "vect.h"

TEST(Vect, vect_new)
{
	t_vect	vect;

	vect = vect_new(1, 2, 3);
	EXPECT_EQ(1, vect.x);
	EXPECT_EQ(2, vect.y);
	EXPECT_EQ(3, vect.z);
}
