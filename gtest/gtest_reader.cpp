#include "reader.h"
#include <gtest/gtest.h>

//テスト用便利関数
bool is_equal_vector(t_vect *act, t_vect *exp) {
  if (!act || !exp)
    return (false);
  return (is_equal(act->x, exp->x) && is_equal(act->y, exp->y) &&
          is_equal(act->z, exp->z));
}

t_circle new_circle(t_vect center, t_vect normal, double radius)
{
  t_circle circle;

  circle.center = center;
  circle.normal = normal;
  circle.radius = radius;
  return (circle);
}

void is_equal_circles(t_data data, t_data exp)
{
  EXPECT_EQ(data.count, exp.count);
  EXPECT_EQ(data.type, exp.type);
  for (int i = 0; i < 100; i++)
  {
    EXPECT_TRUE(is_equal_vector(&data.circle[i].center, &exp.circle[i].center));
    EXPECT_TRUE(is_equal_vector(&data.circle[i].normal, &exp.circle[i].normal));
    EXPECT_TRUE(is_equal(data.circle[i].radius, exp.circle[i].radius));
  }
}

TEST(DISABLED_Reader, InvalidFile) {
  t_data data;

  /*
  EXPECT_FALSE(read_rtfile(&data, NULL));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/hogehoge"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/test.txt"));

  // chmod 000が反映されないので、検証不可能
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/noperm.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/nopermdir/test.rt"));

  //ディレクトリはfopenで読み込み可能
  EXPECT_TRUE(read_rtfile(&data, "gtest/reader_testfiles/invalid/dir.rt"));
  */
}

TEST(DISBALED_Reader, InvalidIdentifier) {
  t_data data = {0};

  /*
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/identifier1.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/identifier2.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/identifier3.rt"));
  */
}

TEST(DISABLED_Reader, InvalidCircleFormat) {
  t_data data = {0};

  /*
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/tr_format1.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/tr_format2.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/tr_format3.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/tr_format4.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/tr_format5.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/tr_format6.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/tr_format7.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/invalid/tr_format8.rt"));
  */
}

TEST(Reader, ReadValidCircleFile) {
  t_data data = {0};
  t_data exp = {0};

  exp.count = 1;
  exp.type = CIRCLE;
  exp.circle[0] = new_circle(vect_new(0,0,0), vect_new(1,0,1), 1.0);
  read_rtfile(&data, "gtest/reader_testfiles/valid/case1.cir");
  is_equal_circles(data, exp);

  exp.count = 4;
  exp.type = CIRCLE;
  exp.circle[0] = new_circle(vect_new(0,0,0), vect_new(0,0,1), 1);
  exp.circle[1] = new_circle(vect_new(0,0,0), vect_new(0,0,1), 2);
  exp.circle[2] = new_circle(vect_new(0,0,0), vect_new(0,0,1), 3);
  exp.circle[3] = new_circle(vect_new(0,0,0), vect_new(0,0,1), 4);
  read_rtfile(&data, "gtest/reader_testfiles/valid/case2.cir");
  is_equal_circles(data, exp);

  exp.count = 20;
  exp.type = CIRCLE;
  for (int i = 0; i < exp.count; i++)
    exp.circle[i] = new_circle(vect_new(0,0,0), vect_new(0,0,1), 1.0);
  read_rtfile(&data, "gtest/reader_testfiles/valid/case3.cir");
  is_equal_circles(data, exp);
}