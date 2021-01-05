#include <cstddef>
#include <iostream>
#include <iterator>

template <class Iterator, class T>
T count_best_coin_greedy(Iterator&& itr_value_start,
                         Iterator&& itr_number_start, std::size_t N, T X) {
  auto itr_value_end = itr_value_start + N;

  T result = 0;

  for (std::size_t i = 0; i < N; ++i) {
    auto itr_value = itr_value_start + i;
    auto itr_number = itr_number_start + i;

    auto add_number = X / (*itr_value);
    if (add_number > *itr_number) add_number = *itr_number;

    X -= (*itr_value * add_number);

    result += add_number;
  }

  return result;
}
