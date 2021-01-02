#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

/**
 * 配列から目的の値を探索する二分探索法
 */
template <class Iterator, class K>
std::size_t _my_binary_search(Iterator&& first, Iterator&& last, K key,
                              std::bidirectional_iterator_tag);

template <class Iterator, class K>
std::size_t my_binary_search(Iterator&& first, Iterator&& last, K key) {
  return _my_binary_search(
      first, last, key,
      typename std::iterator_traits<Iterator>::iterator_category());
}

template <class Iterator, class K>
std::size_t _my_binary_search(Iterator&& first, Iterator&& last, K key,
                              std::bidirectional_iterator_tag) {
  std::size_t left = std::distance(first, first);
  std::size_t right = std::distance(first, std::prev(last));

  while (right >= left) {
    std::size_t mid = left + (right - left) / 2;
    if (*(first + mid) == key) {
      return mid;
    } else if (*(first + mid) > key) {
      right = mid - 1;
    } else if (*(first + mid) < key) {
      left = mid + 1;
    }
  }

  return -1;
}
