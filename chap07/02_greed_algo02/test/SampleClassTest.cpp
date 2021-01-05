#include <gtest/gtest.h>

#include <functional>
#include <vector>

#include "SampleClass.hpp"

TEST(calc, normal) {
  std::vector<int> start_time{1, 5, 3, 2, 9};
  std::vector<int> end_time{9, 6, 5, 4, 2};

  std::vector<std::pair<int, int>> intervals(start_time.size());
  for (std::size_t i = 0; i < intervals.size(); ++i) {
    auto first = start_time[i];
    auto second = end_time[i];
    intervals[i].first = first;
    intervals[i].second = second;
  }

  std::size_t result = max_section_count(intervals);

  ASSERT_EQ(3, result);
}

