#include "load.h"
#include <gtest/gtest.h>

//テスト用便利関数
bool is_equal_vector(t_vect *act, t_vect *exp) {
  if (!act || !exp)
    return (false);
  return (is_equal(act->x, exp->x) && is_equal(act->y, exp->y) &&
          is_equal(act->z, exp->z));
}

void is_equal_triangles(t_data data, t_data exp) {
  EXPECT_EQ(data.count, exp.count);
  for (int i = 0; i < data.count; i++) {
    EXPECT_TRUE(is_equal_vector(&data.object[i].pos1, &exp.object[i].pos1));
    EXPECT_TRUE(is_equal_vector(&data.object[i].pos2, &exp.object[i].pos2));
    EXPECT_TRUE(is_equal_vector(&data.object[i].pos3, &exp.object[i].pos3));
  }
}

t_object new_triangle(t_vect pos1, t_vect pos2, t_vect pos3) {
  t_object triangle;

  triangle.pos1 = pos1;
  triangle.pos2 = pos2;
  triangle.pos3 = pos3;
  return (triangle);
}

TEST(DISABLED_Road, InvalidFile) {
  t_data data;

  // filepath
  EXPECT_EXIT(load_file(&data, NULL), ::testing::ExitedWithCode(EXIT_FAILURE),
              "Filepath is NULL.");
  EXPECT_EXIT(load_file(&data, "invalidpath.tri"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "File does not exist.");

  //.tri extension
  EXPECT_EXIT(load_file(&data, "gtest/reader_testfiles/invalid/test.tr"),
              ::testing::ExitedWithCode(EXIT_FAILURE),
              "Invalid file extension. valid : .tri .");
  EXPECT_EXIT(load_file(&data, "gtest/reader_testfiles/invalid/test.tria"),
              ::testing::ExitedWithCode(EXIT_FAILURE),
              "Invalid file extension. valid : .tri .");
  EXPECT_EXIT(load_file(&data, "gtest/reader_testfiles/invalid/test_tri"),
              ::testing::ExitedWithCode(EXIT_FAILURE),
              "Invalid file extension. valid : .tri .");

  // empty file with valid extension
  EXPECT_EXIT(load_file(&data, "gtest/reader_testfiles/invalid/test.cir.tri"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "");

  // no permission
  /*system("touch gtest/reader_testfiles/invalid/test.cir");
  system("chmod 000 gtest/reader_testfiles/invalid/test.cir");
  EXPECT_EXIT(load_file(&data, "gtest/reader_testfiles/invalid/test.cir.tri"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "count read error.");

  system("mkdir gtest/reader_testfiles/invalid/nopermdir");
  system("touch gtest/reader_testfiles/invalid/nopermdir/test.cir");
  system("chmod 000 gtest/reader_testfiles/invalid/nopermdir");
  EXPECT_EXIT(load_file(&data, "gtest/reader_testfiles/invalid/test.cir.tri"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "count read error.");
  //注意！！　rmする場所を書き換えないように！
  system("chmod 777 gtest/reader_testfiles/invalid/nopermdir");
  system("rm -rf gtest/reader_testfiles/invalid/nopermdir");
  system("rm gtest/reader_testfiles/invalid/test.cir");*/

  // directory
  EXPECT_EXIT(load_file(&data, "gtest/reader_testfiles/invalid/dir.tri"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "");
}

TEST(DISABLED_Load, InvalidTriangleFormat) {
  t_data data = {0};

  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format1.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format2.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format3.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format4.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format5.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format6.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format7.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format8.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format9.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format10.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format11.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format12.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format13.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format14.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      load_file(&data,
                "gtest/reader_testfiles/invalid/triangle_format/format15.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
}

TEST(Load, ValidTriagleFile) {
  fflush(stdout);
  t_data data = {0};
  t_data exp = {0};

  exp.object = (t_object *)ft_xcalloc(20, sizeof(t_object));
  exp.count = 1;
  exp.object[0] =
      new_triangle(vect_new(0, 2, 0), vect_new(2, -2, 0), vect_new(-2, -2, 0));
  load_file(&data, "gtest/reader_testfiles/valid/case1.tri");
  is_equal_triangles(data, exp);
  free(data.object);

  exp.count = 4;
  exp.object[0] =
      new_triangle(vect_new(0, 2, 0), vect_new(2, -2, 0), vect_new(-2, -2, 0));
  exp.object[1] =
      new_triangle(vect_new(0, 2, 0), vect_new(2, -2, 0), vect_new(-2, -2, 0));
  exp.object[2] =
      new_triangle(vect_new(0, 2, 0), vect_new(2, -2, 0), vect_new(-2, -2, 0));
  exp.object[3] =
      new_triangle(vect_new(0, 2, 0), vect_new(2, -2, 0), vect_new(-2, -2, 0));
  load_file(&data, "gtest/reader_testfiles/valid/case2.tri");
  is_equal_triangles(data, exp);
  free(data.object);

  exp.count = 20;
  for (int i = 0; i < exp.count; i++)
    exp.object[i] = new_triangle(vect_new(0, 2, 0), vect_new(2, -2, 0),
                                 vect_new(-2, -2, 0));
  load_file(&data, "gtest/reader_testfiles/valid/case3.tri");
  is_equal_triangles(data, exp);
  free(data.object);
  free(exp.object);
}