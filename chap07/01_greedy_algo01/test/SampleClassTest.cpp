#include <gtest/gtest.h>

#include <vector>

#include "SampleClass.hpp"

TEST(calc, normal) {
  std::vector<int> number_of_coins{4, 5, 6, 6, 8, 9};
  std::vector<int> value_of_coins{500, 100, 50, 10, 5, 1};
  int X = 2456;

  auto result = count_best_coin_greedy(std::begin(value_of_coins),
                                       std::begin(number_of_coins),
                                       number_of_coins.size(), X);

  ASSERT_EQ(11, result);
}

