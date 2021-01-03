#include <algorithm>
#include <limits>

/*
 * ペア和の最小値（ただし k 以上）を求める関数
 */
template <class Container, class T>
T min_pair(Container& a, Container& b, const T K) {
  // N log(N)
  std::sort(b.begin(), b.end());

  T min_value = std::numeric_limits<T>::max();

  for (const auto& iter : a) {
    auto v = std::lower_bound(b.begin(), b.end(), K - iter);

    if ((*v + iter) < min_value) min_value = *v + iter;
  }

  return min_value;
}
