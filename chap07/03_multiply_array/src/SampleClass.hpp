#include <cstddef>

template <class Iterator, class T>
T min_count(Iterator&& a_end_itr, Iterator&& b_end_itr, std::size_t N) {
  T result = 0;
  for (std::size_t i = N - 1; i != 0; --i) {
    auto a_itr = a_end_itr - i;
    auto b_itr = b_end_itr - i;

    // 前回までの操作回数を足し込む
    *a_itr += result;

    // A_{N-1} が B_{N-1} の倍数であるかどうか
    T r = *a_itr % *b_itr;

    if (r == 0) result += (*b_itr - r);
  }

  return result;
}
