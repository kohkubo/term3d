#include "reader.h"
#include <gtest/gtest.h>

//テスト用便利関数
void print_triangle(t_triangle *tri) {
  printf("Triangle\n");
  vect_print(tri->normal);
  vect_print(tri->vert1);
  vect_print(tri->vert2);
  vect_print(tri->vert3);
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

bool is_equal_triangle_list(t_list *act, t_list *exp) {
  while (act && exp) {
    print_triangle(static_cast<t_triangle *>(act->content));
    if (!is_equal_triangle(static_cast<t_triangle *>(act->content),
                           static_cast<t_triangle *>(exp->content)))
      return (false);
    act = act->next;
    exp = exp->next;
  }
  return (!act && !exp);
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
  t_data data = {0};

  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/identifier1.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/identifier2.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/identifier3.rt"));

  ft_lstclear(&data.triangle, free);
}

TEST(Reader, InvalidTRFormat) {
  t_data data = {0};

  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format1.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format2.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format3.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format4.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format5.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format6.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format7.rt"));
  EXPECT_FALSE(read_rtfile(&data, "gtest/reader_testfiles/tr_format8.rt"));

  ft_lstclear(&data.triangle, free);
}

TEST(Reader, ReadTriangle) {
  t_data data = {0};
  t_list *exp;

  t_triangle *tri1;
  tri1 = new_triangle();
  tri1->normal = vect_new(1, 1, 1);
  tri1->vert1 = tri1->vert2 = tri1->vert3 = tri1->normal;
  exp = ft_lstnew(tri1);
  EXPECT_TRUE(read_rtfile(&data, "gtest/reader_testfiles/valid1.rt"));
  EXPECT_TRUE(is_equal_triangle_list(data.triangle, exp));
  ft_lstclear(&data.triangle, free);
  ft_lstclear(&exp, free);

  t_triangle *tri2;
  tri2 = new_triangle();
  tri2->normal = vect_new(-1, -1, -1);
  tri2->vert1 = tri2->vert2 = tri2->vert3 = tri2->normal;
  exp = ft_lstnew(tri2);
  EXPECT_TRUE(read_rtfile(&data, "gtest/reader_testfiles/valid2.rt"));
  EXPECT_TRUE(is_equal_triangle_list(data.triangle, exp));
  ft_lstclear(&data.triangle, free);
  ft_lstclear(&exp, free);

  t_triangle *tri3;
  tri3 = new_triangle();
  tri3->normal =
      vect_new(1.0000000000000001, 1.0000000000000001, 1.0000000000000001);
  tri3->vert1 = tri3->vert2 = tri3->vert3 = tri3->normal;
  exp = ft_lstnew(tri3);
  EXPECT_TRUE(read_rtfile(&data, "gtest/reader_testfiles/valid3.rt"));
  EXPECT_TRUE(is_equal_triangle_list(data.triangle, exp));
  ft_lstclear(&data.triangle, free);
  ft_lstclear(&exp, free);

  t_triangle *tri4;
  tri4 = new_triangle();
  tri4->normal =
      vect_new(-1.0000000000000001, -1.0000000000000001, -1.0000000000000001);
  tri4->vert1 = tri4->vert2 = tri4->vert3 = tri4->normal;
  exp = ft_lstnew(tri4);
  EXPECT_TRUE(read_rtfile(&data, "gtest/reader_testfiles/valid4.rt"));
  EXPECT_TRUE(is_equal_triangle_list(data.triangle, exp));
  ft_lstclear(&data.triangle, free);
  ft_lstclear(&exp, free);

  tri1 = new_triangle();
  tri1->normal = vect_new(1, 1, 1);
  tri1->vert1 = tri1->vert2 = tri1->vert3 = tri1->normal;
  exp = ft_lstnew(tri1);
  tri2 = new_triangle();
  tri2->normal = vect_new(-1, -1, -1);
  tri2->vert1 = tri2->vert2 = tri2->vert3 = tri2->normal;
  ft_lstadd_back(&exp, ft_lstnew(tri2));
  tri3 = new_triangle();
  tri3->normal =
      vect_new(1.0000000000000001, 1.0000000000000001, 1.0000000000000001);
  tri3->vert1 = tri3->vert2 = tri3->vert3 = tri3->normal;
  ft_lstadd_back(&exp, ft_lstnew(tri3));
  tri4 = new_triangle();
  tri4->normal =
      vect_new(-1.0000000000000001, -1.0000000000000001, -1.0000000000000001);
  tri4->vert1 = tri4->vert2 = tri4->vert3 = tri4->normal;
  ft_lstadd_back(&exp, ft_lstnew(tri4));
  EXPECT_TRUE(read_rtfile(&data, "gtest/reader_testfiles/valid5.rt"));
  EXPECT_TRUE(is_equal_triangle_list(data.triangle, exp));
  ft_lstclear(&data.triangle, free);
  ft_lstclear(&exp, free);
}