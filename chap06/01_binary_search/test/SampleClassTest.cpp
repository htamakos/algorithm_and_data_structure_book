#include <gtest/gtest.h>

#include <cstddef>
#include <iterator>
#include <vector>

#include "SampleClass.hpp"

TEST(calc, normal) {
  std::vector<int> v{2, 8, 9, 10, 11};

  std::size_t index = my_binary_search(std::begin(v), std::end(v), 11);

  ASSERT_EQ(4, index);
}

