#include <array>
#include <iostream>
#include <limits>
#include <vector>

namespace myalgo {
namespace stack {
constexpr std::size_t MAX = std::numeric_limits<int>::max();

// スタックを表す配列
std::array<int, MAX> stack_array;

// スタックの先頭を表す添字
std::size_t top_index = 0;

void init() { top_index = 0; }

bool is_emply() { return (top_index == 0); }

bool is_full() { return (top_index == MAX); }

void push(int x) {
  if (is_full()) {
    std::cout << "error: stack is full."
              << "\n";
    return;
  }

  stack_array[top_index] = x;
  ++top_index;
}

int pop() {
  std::cout << top_index << "\n";
  if (is_emply()) {
    std::cout << "error: statck is empty."
              << "\n";
    return -1;
  }

  --top_index;
  return stack_array[top_index];
}
}  // namespace stack
}  // namespace myalgo
