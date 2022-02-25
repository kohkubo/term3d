#include "load.h"
#include <gtest/gtest.h>

void str_to_vector_success_test(char *position, t_vect exp) {
  t_vect act;

  act = str_to_vector(position);
  VECTOR_EQ(exp, act);
}

void str_to_vector_fail_test(char *position) {
  printf("%s\n", position);
  EXPECT_EXIT(str_to_vector(position), testing::ExitedWithCode(1), "");
}

TEST(Load, str_to_vector) {

  //区切る要素の数が異なる
  str_to_vector_fail_test("0");
  str_to_vector_fail_test("0,0");
  str_to_vector_fail_test("0,0,0,0");

  //カンマが必要のない場所にある
  str_to_vector_fail_test("0,0,0,");
  str_to_vector_fail_test(",0,0,0");
  str_to_vector_fail_test(",0,0,0,");
  str_to_vector_fail_test(",0,0,");

  //カンマが３つ以上
  str_to_vector_fail_test("0,,,,0,,,0");
  str_to_vector_fail_test(",,,");
  str_to_vector_fail_test("0,,,");
  str_to_vector_fail_test(",,,0");
  str_to_vector_fail_test("0,,,0");

  //カンマが２つ
  str_to_vector_fail_test("0,,0");

  //数値に変換できない
  str_to_vector_fail_test("inf,inf,inf");
  str_to_vector_fail_test("-inf,-inf,-inf");
  str_to_vector_fail_test("nan,nan,nan");
  str_to_vector_fail_test("a,a,a");
  str_to_vector_fail_test(".,.,.");
  str_to_vector_fail_test("+,+,+");
  str_to_vector_fail_test("-,-,-");
  str_to_vector_fail_test("-0,-0,-0");
  str_to_vector_fail_test("++0,++0,++0");
  str_to_vector_fail_test("--0,--0,--0");
  str_to_vector_fail_test("+-0,+-0,+-0");
  str_to_vector_fail_test("-+0,-+0,-+0");
  str_to_vector_fail_test("\0,\0,\0");
  str_to_vector_fail_test("\n,\n,\n");

  str_to_vector_success_test("0,0,0", vect_new(0, 0, 0));
  str_to_vector_success_test("0.0,0.0,0.0", vect_new(0, 0, 0));
}