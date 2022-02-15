#include <gtest/gtest.h>
#include "data.h"

TEST(Vect, vect_new)
{
	t_vect	vect;

	vect = vect_new(1, 2, 3);
	EXPECT_EQ(1, vect.x);
	EXPECT_EQ(2, vect.y);
	EXPECT_EQ(3, vect.z);
}

TEST(Vect, vect_distance)
{
	t_vect	vect1;
	t_vect	vect2;

	vect1 = vect_new(1, 2, 3);
	vect2 = vect_new(1, 2, 3);
	EXPECT_EQ(0, vect_distance(vect1, vect2));

	// nan
	vect1 = vect_new(1, 2, 3);
	vect2 = vect_new(1, 2, 3);
	vect2.x = NAN;
	EXPECT_EQ(0, vect_distance(vect1, vect2));
}

TEST(Vect, vect_angle)
{
	t_vect vect1 = vect_new(1, 0, 0);
	t_vect vect2 = vect_new(0, 1, 0);

	EXPECT_EQ(radian(90), vect_angle(vect1, vect2));

	vect1 = vect_new(1, 0, 0);
	vect2 = vect_new(0, 0, 1);
	EXPECT_EQ(radian(90), vect_angle(vect1, vect2));
}

TEST(Vect, vect_rotate)
{
	t_vect	vect1 = vect_new(1, 0, 0);
	t_vect	vect2 = vect_new(0, 1, 0);

	vect1 = vect_rotate(vect1, vect2, radian(90));
	EXPECT_EQ(is_equal(0, vect1.x), true);
	EXPECT_EQ(is_equal(0, vect1.y), true);
	EXPECT_EQ(is_equal(-1, vect1.z), true);

	vect1 = vect_rotate(vect1, vect2, radian(90));
	EXPECT_EQ(is_equal(-1, vect1.x), true);
	EXPECT_EQ(is_equal(0, vect1.y), true);
	EXPECT_EQ(is_equal(0, vect1.z), true);

	vect1 = vect_rotate(vect1, vect2, radian(90));
	EXPECT_EQ(is_equal(0, vect1.x), true);
	EXPECT_EQ(is_equal(0, vect1.y), true);
	EXPECT_EQ(is_equal(1, vect1.z), true);
}
