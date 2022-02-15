#include "reader.h"
#include <gtest/gtest.h>

TEST(Reader, InvalidFile) {
  t_data data;

  system("mkdir testfiles");

  EXPECT_FALSE(read_rtfile(&data, NULL));
  system("touch testfiles/test.txt");
  EXPECT_FALSE(read_rtfile(&data, "gtest/testfiles/hogehoge"));

  system("touch testfiles/noperm && chmod 000 testfiles/noperm");
  EXPECT_FALSE(read_rtfile(&data, "gtest/testfiles/test.txt"));

  system("mkdir -p testfiles/dir.rt");
  EXPECT_FALSE(read_rtfile(&data, "gtest/testfiles/noperm"));

  // EXPECT_FALSE(read_rtfile(&data, "gtest/testfiles/dir.rt"));
  system("mkdir testfiles/nopermdir && touch testfiles/nopermdir/test.rt && "
         "chmod 000 testfiles/nopermdir");
  EXPECT_FALSE(read_rtfile(&data, "gtest/testfiles/nopermdir/test.rt"));

  system("chmod 700 testfiles/nopermdir");
  system("rm -rf testfiles");
}

TEST(Reader, ReadTriangle) {}

TEST(Reader, Identifier) {}

TEST(Reader, TriangleFormat) {}