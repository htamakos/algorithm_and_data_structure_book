#include <gtest/gtest.h>

#include <vector>

#include "SampleClass.hpp"

TEST(calc, normal) {
  std::vector<int> v1{9, 8, 7, 6, 5};
  std::vector<int> v2{2, 5, 6, 6, 9};

  const auto k = 0;
  auto result = min_pair(v1, v2, k);

  ASSERT_EQ(7, result);
}

