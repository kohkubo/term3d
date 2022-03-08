#include "load.h"
#include <gtest/gtest.h>

void str_to_vector_success_test(char *position, t_vect exp) {
  t_vect act;

  act = str_to_vector(position);
  VECTOR_EQ(exp, act);
}

void str_to_vector_fail_test(char *position) {
  EXPECT_EXIT(str_to_vector(position), testing::ExitedWithCode(1), "");
}

void arraylentest(char **array, size_t exp_len) {
  EXPECT_EQ(exp_len, arraylen(array));
}

TEST(Load, arraylen) {
  char *array4[5] = {{"0"}, {"0"}, {"0"}, {"0"}, NULL};
  char *array3[4] = {{"0"}, {"0"}, {"0"}, NULL};
  char *array2[3] = {{"0"}, {"0"}, NULL};
  char *array1[2] = {{"0"}, NULL};

  arraylentest(array4, 4);
  arraylentest(array3, 3);
  arraylentest(array2, 2);
  arraylentest(array1, 1);
}

void ft_split_test(char *str, char **exp) {
  char **split;

  split = ft_split(str, ',');
  EXPECT_EQ(arraylen(exp), arraylen(split));
  for (int i = 0; exp[i] && split[i]; i++) {
    EXPECT_STREQ(exp[i], split[i]);
  }
  free_string_array(split);
}

TEST(Load, ft_split) {
  char *array4[5] = {{"0"}, {"0"}, {"0"}, {"0"}, NULL};
  char *array3[4] = {{"0"}, {"0"}, {"0"}, NULL};
  char *array2[3] = {{"0"}, {"0"}, NULL};
  char *array1[2] = {{"0"}, NULL};

  ft_split_test("0,0,0,0", array4);
  ft_split_test("0,,0,0,0", array4);
  ft_split_test("0,0,,0,0", array4);
  ft_split_test("0,0,0,0,", array4);
  ft_split_test("0,0,0,0", array4);
  ft_split_test("0,0,0,,,,0", array4);
  ft_split_test(",,,,,,0,0,0,0", array4);
  ft_split_test("0,0,0", array3);
  ft_split_test("0,0", array2);
  ft_split_test("0", array1);
  ft_split_test("0,", array1);
  ft_split_test(",0,", array1);
  ft_split_test("0,,,", array1);
}

TEST(Load, char_count)
{
  EXPECT_EQ(0, char_count("", ','));
  EXPECT_EQ(0, char_count("0", ','));
  EXPECT_EQ(1, char_count("0,0", ','));
  EXPECT_EQ(1, char_count(",00", ','));
  EXPECT_EQ(1, char_count("00,", ','));
  EXPECT_EQ(2, char_count("0,0,0", ','));
  EXPECT_EQ(2, char_count("0,,0", ','));
  EXPECT_EQ(2, char_count("0,,", ','));
  EXPECT_EQ(3, char_count("0,0,0,0", ','));
  EXPECT_EQ(4, char_count("0,0,0,0,0", ','));
  EXPECT_EQ(5, char_count("0,0,0,0,0,0", ','));
}

TEST(Load, str_to_vector)
{
  //カンマが３つ以上
  str_to_vector_fail_test("0,,,,0,,,0");
  str_to_vector_fail_test(",,,");
  str_to_vector_fail_test("0,,,");
  str_to_vector_fail_test(",,,0");
  str_to_vector_fail_test("0,,,0");
  str_to_vector_fail_test("0,0,0,");

  //カンマが２つ
  str_to_vector_fail_test("0,,0");

  //カンマが１つ
  str_to_vector_fail_test(",0");
  str_to_vector_fail_test("0,");
  str_to_vector_fail_test(",");

  //区切る要素の数が異なる
  str_to_vector_fail_test("0");
  str_to_vector_fail_test("0,0");
  str_to_vector_fail_test("0,0,0,0");

  //カンマが必要のない場所にある
  str_to_vector_fail_test("0,0,0,");
  str_to_vector_fail_test(",0,0,0");
  str_to_vector_fail_test(",0,0,0,");

  str_to_vector_success_test("0,0,0", vect_new(0, 0, 0));
  str_to_vector_success_test("0.0,0.0,0.0", vect_new(0, 0, 0));
}

TEST(Load, strtod_wrapper) {
  // OK case
  EXPECT_EQ(strtod_wrapper("0"), 0);
  EXPECT_EQ(strtod_wrapper("0.0"), 0);
  EXPECT_EQ(strtod_wrapper("-0.0"), 0);
  EXPECT_EQ(strtod_wrapper("-0"), 0);

  // 注意するケース
  EXPECT_EQ(strtod_wrapper(".0"), 0);
  EXPECT_EQ(strtod_wrapper("0."), 0);
  EXPECT_EQ(strtod_wrapper("-0."), 0);
  EXPECT_EQ(strtod_wrapper("+0."), 0);
  EXPECT_DEATH(strtod_wrapper("+0f"), "");

  // NG case
  EXPECT_DEATH(strtod_wrapper(""), "");
  EXPECT_DEATH(strtod_wrapper("inf"), "");
  EXPECT_DEATH(strtod_wrapper("-inf"), "");
  EXPECT_DEATH(strtod_wrapper("nan"), "");
  EXPECT_DEATH(strtod_wrapper("-nan"), "");
  EXPECT_DEATH(strtod_wrapper("a"), "");
  EXPECT_DEATH(strtod_wrapper("."), "");
  EXPECT_DEATH(strtod_wrapper("+"), "");
  EXPECT_DEATH(strtod_wrapper("-"), "");
  EXPECT_DEATH(strtod_wrapper("++0"), "");
  EXPECT_DEATH(strtod_wrapper("--0"), "");
  EXPECT_DEATH(strtod_wrapper("+-0"), "");
  EXPECT_DEATH(strtod_wrapper("-+0"), "");
  EXPECT_DEATH(strtod_wrapper("\0"), "");
  EXPECT_DEATH(strtod_wrapper("\n"), "");
  EXPECT_DEATH(strtod_wrapper("0..0"), "");
  EXPECT_DEATH(strtod_wrapper("0.0."), "");
}

void test_fscanf(char *s) {
  char buf[2048];
  FILE *fp = fmemopen(buf, sizeof(buf), "w");
  fprintf(fp, "%s", s);
  fclose(fp);

  char result[2048];
  fp = fmemopen(buf, sizeof(buf), "r");
  EXPECT_EQ(fscanf(fp, "%s", result), 1);
  EXPECT_EQ(strcmp(result, s), 0);
  fclose(fp);
}

TEST(Load, fscanf) {
  test_fscanf("0");
  test_fscanf("0.0");
  test_fscanf("-0.0");
}