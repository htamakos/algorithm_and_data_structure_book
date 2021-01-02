#include "SampleClass.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(knapsack, return_max_value)
{
  int N = 6;
  long long W = 15;
  std::vector<long long> weight { 2, 1, 3, 2, 1, 5 };
  std::vector<long long> value { 3, 2, 6, 1, 3, 85 };

  auto actual_value = knapsack<long long>(weight, value, N, W);
  auto expected_value = 100LL;
  
  ASSERT_EQ(expected_value, actual_value);
}

