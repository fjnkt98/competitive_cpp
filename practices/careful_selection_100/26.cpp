/*
 * https://atcoder.jp/contests/abc138/tasks/abc138_d
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void dfs(std::vector<std::vector<int64_t>>& graph,
        std::vector<int64_t>& counter,
        int64_t previous_node,
        int64_t current_node)
{
  for (auto next_node : graph.at(current_node)) {
    if (next_node != previous_node) {
      counter.at(next_node) += counter.at(current_node);
      dfs(graph, counter, current_node, next_node);
    }
  }
}

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N - 1; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    graph.at(a - 1).push_back(b - 1);
    graph.at(b - 1).push_back(a - 1);
  }

  std::vector<int64_t> counter(N, 0);
  for (int64_t i = 0; i < Q; i++) {
    int64_t p, x;
    std::cin >> p >> x;
    counter.at(p - 1) += x;
  }

  dfs(graph, counter, -1, 0);

  for (auto c : counter) {
    std::cout << c << std::endl;
  }

  return 0;
}
