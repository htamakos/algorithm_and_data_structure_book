#include <gtest/gtest.h>

#include <iterator>
#include <utility>
#include <vector>

#include "SampleClass.hpp"

TEST(calc, normal) {
  std::vector<long long> a{0, 1, 3, 8, 11, 7, 12};
  std::vector<long long> b{1, 2, 8, 8, 10, 5, 2};

  auto result = min_count<decltype(std::end(a)), long long>(
      std::end(a), std::end(b), a.size());
  ASSERT_EQ(13, result);
}

