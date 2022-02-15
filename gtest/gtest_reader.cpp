#include "reader.h"
#include <gtest/gtest.h>

//テスト用便利関数
void init_triangle(t_data *data) {
  data->triangle = static_cast<t_triangle *>(malloc(sizeof(t_triangle)));
  data->triangle->normal = vect_new(0, 0, 0);
  data->triangle->vert1 = vect_new(0, 0, 0);
  data->triangle->vert2 = vect_new(0, 0, 0);
  data->triangle->vert3 = vect_new(0, 0, 0);
  data->triangle->next = NULL;
}

bool is_equal_vector(t_vect *act, t_vect *exp) {
  if (!act || !exp)
    return (false);
  return (is_equal(act->x, exp->x) && is_equal(act->y, exp->y) &&
          is_equal(act->z, exp->z));
}

bool is_equal_triangle(t_triangle *act, t_triangle *exp) {
  if (!act || !exp)
    return (false);
  return (is_equal_vector(&act->normal, &exp->normal) &&
          is_equal_vector(&act->vert1, &exp->vert1) &&
          is_equal_vector(&act->vert2, &exp->vert2) &&
          is_equal_vector(&act->vert3, &exp->vert3));
}

TEST(DISABLED_Reader, InvalidFile) {
  t_data data;

  EXPECT_FALSE(read_rtfile(&data, NULL));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/hogehoge"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/test.txt"));

  // chmod 000が反映されないので、検証不可能
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/noperm.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/nopermdir/test.rt"));

  //ディレクトリはfopenで読み込み可能
  EXPECT_TRUE(read_rtfile(&data, "gtest/reader_testfiles/dir.rt"));
}

TEST(Reader, InvalidIdentifier) {
  t_data data;

  init_triangle(&data);
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/identifier1.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/identifier2.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/identifier3.rt"));
}

TEST(Reader, InvalidTRFormat) {
  t_data data;

  init_triangle(&data);
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format1.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format2.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format3.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format4.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format5.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format6.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format7.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format8.rt"));
}

TEST(Reader, ReadTriangle) {
  t_data data1;
  init_triangle(&data1);
  t_triangle exp1;
  exp1.normal = vect_new(1, 1, 1);
  exp1.vert1 = exp1.normal;
  exp1.vert2 = exp1.vert1;
  exp1.vert3 = exp1.vert2;
  EXPECT_TRUE(read_rtfile(&data1, "gtest/reader_testfiles/valid1.rt"));
  EXPECT_TRUE(is_equal_triangle(data1.triangle, &exp1));

  t_data data2;
  init_triangle(&data2);
  t_triangle exp2;
  exp2.normal = vect_new(-1, -1, -1);
  exp2.vert1 = exp2.normal;
  exp2.vert2 = exp2.vert1;
  exp2.vert3 = exp2.vert2;
  EXPECT_TRUE(read_rtfile(&data2, "gtest/reader_testfiles/valid2.rt"));
  EXPECT_TRUE(is_equal_triangle(data2.triangle, &exp2));

  t_data data3;
  init_triangle(&data3);
  t_triangle exp3;
  exp3.normal =
      vect_new(1.0000000000000001, 1.0000000000000001, 1.0000000000000001);
  exp3.vert1 = exp3.normal;
  exp3.vert2 = exp3.vert1;
  exp3.vert3 = exp3.vert2;
  EXPECT_TRUE(read_rtfile(&data3, "gtest/reader_testfiles/valid3.rt"));
  EXPECT_TRUE(is_equal_triangle(data3.triangle, &exp3));

  t_data data4;
  init_triangle(&data4);
  t_triangle exp4;
  exp4.normal =
      vect_new(-1.0000000000000001, -1.0000000000000001, -1.0000000000000001);
  exp4.vert1 = exp4.normal;
  exp4.vert2 = exp4.vert1;
  exp4.vert3 = exp4.vert2;
  EXPECT_TRUE(read_rtfile(&data4, "gtest/reader_testfiles/valid4.rt"));
  EXPECT_TRUE(is_equal_triangle(data4.triangle, &exp4));
}