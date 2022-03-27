#include "vect.h"
#include <gtest/gtest.h>

void write_teststr(const char *str, char *buf, size_t length) {
  FILE *fp = fmemopen(buf, sizeof(buf) * length, "w");
  fprintf(fp, "%s", str);
  fclose(fp);
}

void test_getline(const char *str, const char *exp) {
  char *lineptr = NULL;
  size_t len = 0;
  FILE *stream;

  char buf[strlen(str)];

  write_teststr(str, buf, strlen(str));
  stream = fmemopen(buf, sizeof(buf), "r");

  EXPECT_EQ(getline(&lineptr, &len, stream), strlen(exp));
  EXPECT_STREQ(lineptr, exp);
  fclose(stream);
  free(lineptr);
}

TEST(GetLine, getline) {
  test_getline("0", "0");
  test_getline("0.0", "0.0");
  test_getline("-0.0", "-0.0");

  //改行文字を含める
  test_getline("0.0\n0", "0.0\n");

  std::string str;

  //可変長(1024文字以上)の文字を受け取れる
  str = std::string(1024, '0');
  test_getline(str.c_str(), str.c_str());

  str = std::string(1025, '0');
  test_getline(str.c_str(), str.c_str());

  str = std::string(1024, ' ') + std::string(10, '0');
  test_getline(str.c_str(), str.c_str());

  str = std::string(10, '0') + std::string(1024, ' ');
  test_getline(str.c_str(), str.c_str());

  str = std::string(10, '0') + std::string(1024, ' ') + std::string(10, '0');
  test_getline(str.c_str(), str.c_str());
}

/*
bool  vect_isfinite(t_vect *vect) {
  return (isfinite(vect->x) || isfinite(vect->y) || isfinite(vect->z));
}

bool test_fscanf(char *str, t_vect *pos1, t_vect *pos2, t_vect *pos3) {
  //テストの関係で最初に弾くケース
  if (!str || str[0] == '\0')
    return (false);

  FILE *file;
  char buf[strlen(str)];
  write_teststr(str, buf, strlen(str));
  file = fmemopen(buf, sizeof(buf), "r");

  if (fscanf(file, "%lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf", &pos1->x, &pos1->y,
             &pos1->z, &pos2->x, &pos2->y, &pos2->z, &pos3->x, &pos3->y,
             &pos3->z) != 9)
    return (false);
  if (!vect_isfinite(pos1) || !vect_isfinite(pos2) || !vect_isfinite(pos3))
    return (false);
  return (true);
}

bool invalidtest_fscanf(char *str) {
  t_vect pos1;
  t_vect pos2;
  t_vect pos3;
  return test_fscanf(str, &pos1, &pos2, &pos3);
}

void validtest_fscanf(char *str, t_vect exp1, t_vect exp2, t_vect exp3) {
  t_vect pos1;
  t_vect pos2;
  t_vect pos3;
  EXPECT_TRUE(test_fscanf(str, &pos1, &pos2, &pos3));
  VECTOR_EQ(pos1, exp1);
  VECTOR_EQ(pos2, exp2);
  VECTOR_EQ(pos3, exp3);
}

TEST(GetLine, valid_fscanf) {
  validtest_fscanf("-0.196075,0.310578,-0.037432 -0.307269,0.319429,-0.036707 -0.250826,0.321744,-0.036041", t_vect{-0.196075,0.310578,-0.037432}, t_vect{-0.307269,0.319429,-0.036707}, t_vect{-0.250826,0.321744,-0.036041});
}

//testfiles直下の全テストを試している
TEST(GetLine, invalid_fscanf) {
  EXPECT_FALSE(invalidtest_fscanf("2a,-2,0 0,2,0 -2,-2,0"));
  EXPECT_FALSE(invalidtest_fscanf("2,-2,0 0,a2,0 -2,-2,0"));
  EXPECT_FALSE(invalidtest_fscanf("2a,-2,0 0,2.a0,0 -2,-2,0"));
  EXPECT_FALSE(
      invalidtest_fscanf("0,,0,,0 0,,,,,,,,0,,,,,,,,0 0,,,,0,,,,,,,,,,0"));
  EXPECT_FALSE(invalidtest_fscanf(
      "                                                                        "
      "                                                                    "));
  EXPECT_FALSE(invalidtest_fscanf(
      "900000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000001,0,0 9,0,9 2,2,2"));
  EXPECT_FALSE(invalidtest_fscanf("2,-2,0 0,2,0 -2,-2,inf"));
  EXPECT_FALSE(invalidtest_fscanf(
      "-90000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "0000000000000000000001,0,0 9,0,9 2,2,2"));
  EXPECT_FALSE(invalidtest_fscanf("2,-2,0 0,2,0 -2,--2,0"));
  EXPECT_FALSE(invalidtest_fscanf("2,-2,0 0,nan,0 -2,-2,0"));
  EXPECT_FALSE(invalidtest_fscanf("2,-2,0 0,2,0 -2,++2,0"));
  EXPECT_FALSE(invalidtest_fscanf(
      "0,0,0 0,0,0 "
      "0,0,0."
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000000000000000000000000000000001"
      "0"));
  EXPECT_FALSE(invalidtest_fscanf(
      "0,0,0 0,0,0 0,0,0                                                       "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "               10"));
  EXPECT_FALSE(invalidtest_fscanf(
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "0,0,0 0,0,0 0,0,0"));
  EXPECT_FALSE(invalidtest_fscanf(
      "                               0,0,0                                    "
      "       0,0,0                                                            "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "                                                                        "
      "            0,0,0"));
  EXPECT_FALSE(invalidtest_fscanf(
      "-0.116008.0,6.709811.0,4.749132.0 0.082873.0,6.584992.0,4.711259.0 "
      "0.146821.0,6.681798.0,4.713804.0"));
  EXPECT_FALSE(invalidtest_fscanf("0,0,0, 0,0,0, 0,0,0,"));
  EXPECT_FALSE(invalidtest_fscanf("-0.116008,6.709811,4.749132,4.749132 "
                                  "0.082873,6.584992,4.711259,4.711259 "
                                  "0.146821,6.681798,4.713804,4.713804"));
  EXPECT_FALSE(invalidtest_fscanf(",0,0,0 ,0,0,0 ,0,0,0"));
  EXPECT_FALSE(invalidtest_fscanf("-0.116008 0.082873 0.146821"));
  EXPECT_FALSE(invalidtest_fscanf(".,.,. .,.,. .,.,."));
  EXPECT_FALSE(invalidtest_fscanf("-,-,- -,-,- -,-,-"));
  EXPECT_FALSE(invalidtest_fscanf(
      "-0.116008,6.709811 0.082873,6.584992 0.146821,6.681798"));
  EXPECT_FALSE(invalidtest_fscanf(
      "-0.116008,6.709811,4.749132 0.082873,6.584992,4.711259 "
      "0.146821,6.681798,4.713804 0.146821,6.681798,4.713804 "));
  EXPECT_FALSE(invalidtest_fscanf("-0.116008,6.709811,4.749132"));
  EXPECT_FALSE(invalidtest_fscanf(
      "-0.116008,6.709811,4.749132 0.082873,6.584992,4.711259"));
  EXPECT_FALSE(invalidtest_fscanf(
      "-0.116008.6.709811.4.749132 0.082873.6.584992.4.711259 "
      "0.146821.6.681798.4.713804"));
}
*/