#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

template <class T>
using Graph = std::vector<std::vector<T>>;

template <class T>
void search(const Graph<T> G, T s, std::ostream& os = std::cout) {
  std::size_t N = G.size();

  std::vector<bool> seen(N, false);
  std::queue<T> todo;

  seen[s] = true;
  todo.push(s);

  while (!todo.empty()) {
    T v = todo.front();
    todo.pop();

    for (T x : G[v]) {
      if (seen[x]) continue;

      os << x << " ";
      seen[x] = true;
      todo.push(x);
    }
  }
}

template <class T>
void _dfs(Graph<T> G, T v, std::vector<bool>& seen,
          std::ostream& os = std::cout) {
  seen[v] = true;

  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;
    os << next_v << " ";

    _dfs(G, next_v, seen, os);
  }
}

template <class T>
void dfs(Graph<T> G, T root, std::ostream& os = std::cout) {
  std::size_t N = G.size();
  std::vector<bool> seen(N, false);

  _dfs(G, root, seen, os);
}

