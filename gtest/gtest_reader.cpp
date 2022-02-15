#include "reader.h"
#include <gtest/gtest.h>

//テスト用便利関数
void init_triangle(t_data *data) {
  data->triangle = static_cast<t_triangle *>(malloc(sizeof(t_triangle)));
  data->triangle->normal = vect_new(0, 0, 0);
  data->triangle->vert1 = vect_new(0, 0, 0);
  data->triangle->vert2 = vect_new(0, 0, 0);
  data->triangle->vert3 = vect_new(0, 0, 0);
}

bool is_equal_vector(t_vect *act, t_vect *exp) {
  return (is_equal(act->x, exp->x) && is_equal(act->y, exp->y) &&
          is_equal(act->z, exp->z));
}

bool is_equal_triangle(t_triangle *act, t_triangle *exp) {
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