#include <array>
#include <iostream>
#include <vector>

namespace myalgo {
namespace queue {
constexpr std::size_t MAX = 1000;
std::array<int, MAX> queue_array;

// キューの要素区間を表す添字
int tail = 0, head = 0;

void init() { head = tail = 0; }

bool is_empty() { return (head == tail); }

bool is_full() { return (head == (tail + 1) % MAX); }

void enqueue(int x) {
  if (is_full()) {
    std::cout << "error: queue is full"
              << "\n";
    return;
  }

  queue_array[tail] = x;
  ++tail;
  if (tail == MAX) tail = 0;
}

int dequeue() {
  if (is_empty()) {
    std::cout << "error: queue is empty"
              << "\n";
    return -1;
  }

  int res = queue_array[head];
  ++head;
  if (head == MAX) head = 0;
  return res;
}

}  // namespace queue
}  // namespace myalgo
