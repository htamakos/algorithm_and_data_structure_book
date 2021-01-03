#include <gtest/gtest.h>

#include <vector>

#include "SampleClass.hpp"

TEST(calc, normal) {
  long long N = 5;
  std::vector<long long> h{4, 5, 8, 9, 12};
  std::vector<long long> s{1, 3, 4, 5, 7};

  ASSERT_EQ(16, find_min_penalty(std::begin(h), std::begin(s), N));
}

