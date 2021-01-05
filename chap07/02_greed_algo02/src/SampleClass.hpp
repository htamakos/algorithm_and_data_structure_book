#include <algorithm>
#include <cstddef>
#include <functional>
#include <vector>

template <class T>
using Interval = std::pair<T, T>;

template <class T>
bool cmp_pair(const Interval<T>& a, const Interval<T>& b) {
  return a.second < b.second;
}

template <class T>
std::size_t max_section_count(std::vector<Interval<T>>& intervals) {
  std::size_t result = 0;

  std::sort(intervals.begin(), intervals.end(), cmp_pair<T>);

  T current_end_time = 0;

  for (auto& interval : intervals) {
    if (interval.first < current_end_time) continue;

    ++result;
    current_end_time = interval.second;
  }

  return result;
}
