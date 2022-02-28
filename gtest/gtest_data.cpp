#include <gtest/gtest.h>

#include "data.h"

#define SWAP(a, b) { double tmp = a; a = b; b = tmp; }

/*
// doubleの比較
TEST(DISABLED_Data, is_equal) {
  double a = 1.0;
  double b = 1.0;
  EXPECT_EQ(is_equal(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), true);
  a = 1.0;
  b = 2.0;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.01;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.0001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.00001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.00001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.000001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.0000001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.00000001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.000000001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.0000000001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.00000000001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.000000000001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.0000000000001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.00000000000001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  a = 1.0;
  b = 1.000000000000001;
  EXPECT_EQ(is_equal(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), false);
  // DBL_EPSILONの限界
  a = 1.0;
  b = 1.0000000000000001;
  EXPECT_EQ(is_equal(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), true);
  a = 1.0;
  b = 1.00000000000000001;
  EXPECT_EQ(is_equal(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), true);
  a = 1.0;
  b = 1.000000000000000001;
  EXPECT_EQ(is_equal(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(is_equal(a, b), true);
}

TEST(DISABLED_Data, less) {
  double a = 1.0;
  double b = 1.0;
  EXPECT_EQ(less(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 2.0;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 2.0;
  b = 1.0;
  EXPECT_EQ(less(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), true);
  a = 1.0;
  b = 1.01;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.0001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.00001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.00001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.000001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.0000001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.00000001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.000000001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.0000000001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.00000000001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.000000000001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.0000000000001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.00000000000001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.000000000000001;
  EXPECT_EQ(less(a, b), true);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  // DBL_EPSILONの境界
  a = 1.0;
  b = 1.0000000000000001;
  EXPECT_EQ(less(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.00000000000000001;
  EXPECT_EQ(less(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
  a = 1.0;
  b = 1.000000000000000001;
  EXPECT_EQ(less(a, b), false);
  SWAP(a, b);
  EXPECT_EQ(less(a, b), false);
}
*/

TEST(Data, radian)
{
  EXPECT_EQ(radian(0.0), 0.0);
  EXPECT_EQ(radian(90.0), M_PI_2);
  EXPECT_EQ(radian(180.0), M_PI);
  EXPECT_EQ(radian(270.0), M_PI_2 * 3.0);
  EXPECT_EQ(radian(360.0), M_PI * 2.0);
}


/*
TEST(Data, less_equal)
{
  EXPECT_EQ(less_equal(0.0, 0.0), true);
  EXPECT_EQ(less_equal(0.0, 1.0), true);

  EXPECT_EQ(less_equal(1.0, 0.0), false);
  EXPECT_EQ(less_equal(1.0, 1.0), true);
  EXPECT_EQ(less_equal(1.0, 2.0), true);
  EXPECT_EQ(less_equal(2.0, 1.0), false);
  EXPECT_EQ(less_equal(2.0, 2.0), true);
  EXPECT_EQ(less_equal(0.00001, 0.00001), true);
  EXPECT_EQ(less_equal(0.00001, 0.00002), true);
  EXPECT_EQ(less_equal(0.00002, 0.00001), false);
  EXPECT_EQ(less_equal(0.000001, 0.000001), true);
}
*/
