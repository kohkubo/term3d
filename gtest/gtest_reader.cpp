#include "reader.h"
#include <gtest/gtest.h>

//テスト用便利関数
bool is_equal_vector(t_vect *act, t_vect *exp) {
  if (!act || !exp)
    return (false);
  return (is_equal(act->x, exp->x) && is_equal(act->y, exp->y) &&
          is_equal(act->z, exp->z));
}

void is_equal_circles(t_data data, t_data exp) {
  EXPECT_EQ(data.count, exp.count);
  EXPECT_EQ(data.type, exp.type);
  for (int i = 0; i < data.count; i++) {
    EXPECT_TRUE(is_equal_vector(&data.object[i].pos1, &exp.object[i].pos1));
    EXPECT_TRUE(is_equal_vector(&data.object[i].normal, &exp.object[i].normal));
    EXPECT_TRUE(is_equal(data.object[i].radius, exp.object[i].radius));
  }
}

void is_equal_triangles(t_data data, t_data exp) {
  EXPECT_EQ(data.count, exp.count);
  EXPECT_EQ(data.type, exp.type);
  for (int i = 0; i < data.count; i++) {
    EXPECT_TRUE(
        is_equal_vector(&data.object[i].pos1, &exp.object[i].pos1));
    EXPECT_TRUE(
        is_equal_vector(&data.object[i].pos2, &exp.object[i].pos2));
    EXPECT_TRUE(
        is_equal_vector(&data.object[i].pos3, &exp.object[i].pos3));
    EXPECT_TRUE(
        is_equal_vector(&data.object[i].normal, &exp.object[i].normal));
  }
}

t_object new_circle(t_vect center, t_vect normal, double radius) {
  t_object circle;

  circle.pos1 = center;
  circle.normal = normal;
  circle.radius = radius;
  return (circle);
}

t_object new_triangle(t_vect vert1, t_vect vert2, t_vect vert3,
                        t_vect normal) {
  t_object triangle;

  triangle.pos1 = vert1;
  triangle.pos2 = vert2;
  triangle.pos3 = vert3;
  triangle.normal = normal;
  return (triangle);
}

TEST(Reader, InvalidFile) {
  t_data data;

  // filepath
  EXPECT_EXIT(read_rtfile(&data, NULL), ::testing::ExitedWithCode(EXIT_FAILURE),
              "does not filepath.");
  EXPECT_EXIT(read_rtfile(&data, "invalidpath.cir"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(read_rtfile(&data, "invalidpath.tri"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "");

  //.cir extension
  EXPECT_EXIT(read_rtfile(&data, "gtest/reader_testfiles/invalid/test.ci"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "file extension error.");
  EXPECT_EXIT(read_rtfile(&data, "gtest/reader_testfiles/invalid/test.circ"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "file extension error.");
  EXPECT_EXIT(read_rtfile(&data, "gtest/reader_testfiles/invalid/test_cir"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "file extension error.");

  //.tri extension
  EXPECT_EXIT(read_rtfile(&data, "gtest/reader_testfiles/invalid/test.tr"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "file extension error.");
  EXPECT_EXIT(read_rtfile(&data, "gtest/reader_testfiles/invalid/test.tria"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "file extension error.");
  EXPECT_EXIT(read_rtfile(&data, "gtest/reader_testfiles/invalid/test_tri"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "file extension error.");

  // empty file with valid extension
  EXPECT_EXIT(read_rtfile(&data, "gtest/reader_testfiles/invalid/test.tri.cir"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "count read error.");
  EXPECT_EXIT(read_rtfile(&data, "gtest/reader_testfiles/invalid/test.cir.tri"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "count read error.");

  // no permission
  /*system("touch gtest/reader_testfiles/invalid/test.cir");
  system("chmod 000 gtest/reader_testfiles/invalid/test.cir");
  EXPECT_EXIT(read_rtfile(&data, "gtest/reader_testfiles/invalid/test.cir.tri"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "count read error.");

  system("mkdir gtest/reader_testfiles/invalid/nopermdir");
  system("touch gtest/reader_testfiles/invalid/nopermdir/test.cir");
  system("chmod 000 gtest/reader_testfiles/invalid/nopermdir");
  EXPECT_EXIT(read_rtfile(&data, "gtest/reader_testfiles/invalid/test.cir.tri"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "count read error.");
  //注意！！　rmする場所を書き換えないように！
  system("chmod 777 gtest/reader_testfiles/invalid/nopermdir");
  system("rm -rf gtest/reader_testfiles/invalid/nopermdir");
  system("rm gtest/reader_testfiles/invalid/test.cir");*/

  // directory
  EXPECT_EXIT(read_rtfile(&data, "gtest/reader_testfiles/invalid/dir.cir"),
              ::testing::ExitedWithCode(EXIT_FAILURE), "");
}

TEST(Reader, InvalidCircleFormat) {
  t_data data = {0};

  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format1.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format2.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format3.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format4.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format5.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format6.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format7.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format8.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  /*EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format9.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");*/
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format10.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format11.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format12.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format12.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format14.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format15.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format16.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/circle_format/format17.cir"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
}

TEST(Reader, InvalidTriangleFormat) {
  t_data data = {0};

  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/triangle_format/format1.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/triangle_format/format2.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/triangle_format/format3.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/triangle_format/format4.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/triangle_format/format5.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/triangle_format/format6.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/triangle_format/format7.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  /*EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/triangle_format/format8.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");*/
  EXPECT_EXIT(
      read_rtfile(&data,
                  "gtest/reader_testfiles/invalid/triangle_format/format9.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(
          &data, "gtest/reader_testfiles/invalid/triangle_format/format10.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(
          &data, "gtest/reader_testfiles/invalid/triangle_format/format11.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(
          &data, "gtest/reader_testfiles/invalid/triangle_format/format12.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(
          &data, "gtest/reader_testfiles/invalid/triangle_format/format13.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(
          &data, "gtest/reader_testfiles/invalid/triangle_format/format14.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
  EXPECT_EXIT(
      read_rtfile(
          &data, "gtest/reader_testfiles/invalid/triangle_format/format15.tri"),
      ::testing::ExitedWithCode(EXIT_FAILURE), "");
}

TEST(Reader, ValidCircleFile) {
  t_data data = {0};
  t_data exp = {0};

  exp.count = 1;
  exp.type = CIRCLE;
  exp.object[0] = new_circle(vect_new(0, 0, 0), vect_new(1, 0, 1), 1.0);
  read_rtfile(&data, "gtest/reader_testfiles/valid/case1.cir");
  is_equal_circles(data, exp);

  exp.count = 4;
  exp.type = CIRCLE;
  exp.object[0] = new_circle(vect_new(0, 0, 0), vect_new(0, 0, 1), 1);
  exp.object[1] = new_circle(vect_new(0, 0, 0), vect_new(0, 0, 1), 2);
  exp.object[2] = new_circle(vect_new(0, 0, 0), vect_new(0, 0, 1), 3);
  exp.object[3] = new_circle(vect_new(0, 0, 0), vect_new(0, 0, 1), 4);
  read_rtfile(&data, "gtest/reader_testfiles/valid/case2.cir");
  is_equal_circles(data, exp);

  exp.count = 20;
  exp.type = CIRCLE;
  for (int i = 0; i < exp.count; i++)
    exp.object[i] = new_circle(vect_new(0, 0, 0), vect_new(0, 0, 1), 1.0);
  read_rtfile(&data, "gtest/reader_testfiles/valid/case3.cir");
  is_equal_circles(data, exp);
}

TEST(Reader, ValidTriagleFile) {
  t_data data = {0};
  t_data exp = {0};

  exp.count = 1;
  exp.type = TRIANGLE;
  exp.object[0] = new_triangle(vect_new(0, 2, 0), vect_new(2, -2, 0),
                                 vect_new(-2, -2, 0), vect_new(0, 0, 1));
  read_rtfile(&data, "gtest/reader_testfiles/valid/case1.tri");
  is_equal_triangles(data, exp);

  exp.count = 4;
  exp.type = TRIANGLE;
  exp.object[0] = new_triangle(vect_new(0, 2, 0), vect_new(2, -2, 0),
                                 vect_new(-2, -2, 0), vect_new(0, 0, 1));
  exp.object[1] = new_triangle(vect_new(0, 2, 0), vect_new(2, -2, 0),
                                 vect_new(-2, -2, 0), vect_new(0, 0, 1));
  exp.object[2] = new_triangle(vect_new(0, 2, 0), vect_new(2, -2, 0),
                                 vect_new(-2, -2, 0), vect_new(0, 0, 1));
  exp.object[3] = new_triangle(vect_new(0, 2, 0), vect_new(2, -2, 0),
                                 vect_new(-2, -2, 0), vect_new(0, 0, 1));
  read_rtfile(&data, "gtest/reader_testfiles/valid/case2.tri");
  is_equal_triangles(data, exp);

  exp.count = 20;
  exp.type = TRIANGLE;
  for (int i = 0; i < exp.count; i++)
    exp.object[i] = new_triangle(vect_new(0, 2, 0), vect_new(2, -2, 0),
                                   vect_new(-2, -2, 0), vect_new(0, 0, 1));
  read_rtfile(&data, "gtest/reader_testfiles/valid/case3.tri");
  is_equal_triangles(data, exp);
}