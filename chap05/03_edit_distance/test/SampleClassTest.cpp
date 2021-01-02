#include <gtest/gtest.h>

#include <string>

#include "SampleClass.hpp"

TEST(calc, normal) {
  std::string s = "logistic";
  std::string t = "algorithm";

  ASSERT_EQ(6, edit_distance(s, t));
}

