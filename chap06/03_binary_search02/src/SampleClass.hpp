#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

template <class Iterator, class T>
T find_min_penalty(Iterator&& h_start, Iterator&& s_start, T N) {
  T left = 0;
  T right = std::numeric_limits<T>::max();

  while (right - left > 1) {
    T mid = (left + right) / 2;
    bool ok = true;

    std::vector<T> t(N, 0);

    for (auto index = 0; index < N; ++index) {
      auto h_iter = h_start + index;
      auto s_iter = s_start + index;

      if (mid < *h_iter)
        ok = false;
      else
        t[index] = (mid - *h_iter) / *s_iter;
    }

    std::sort(t.begin(), t.end());
    for (auto i = 0; i < N; ++i) {
      if (t[i] < i) ok = false;
    }

    if (ok)
      right = mid;
    else
      left = mid;
  }

  return right;
}
