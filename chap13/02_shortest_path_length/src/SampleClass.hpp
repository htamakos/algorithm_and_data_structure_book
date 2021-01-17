#include <queue>
#include <vector>

template <class T>
using Graph = std::vector<std::vector<T>>;

template <class T>
std::vector<T> spBFS(const Graph<T> &G, T root) {
  std::size_t N = G.size();

  // 最短経路長を記録するためのリスト
  std::vector<T> dist(N, -1);
  dist[root] = 0;

  std::queue<T> todo;
  todo.push(root);

  while (!todo.empty()) {
    T v = todo.front();
    todo.pop();

    for (auto next_v : G[v]) {
      if (dist[next_v] != -1) continue;

      dist[next_v] = dist[v] + 1;
      todo.push(next_v);
    }
  }

  return dist;
}
