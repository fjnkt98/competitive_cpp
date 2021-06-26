/*
 * Calculate the amount of connected component by using DFS
 */

#include <iostream>
#include <vector>

std::vector<bool> explored;

void dfs(const std::vector<std::vector<int64_t>>& graph, int64_t node) {
  explored.at(node) = true;

  for (auto next_node : graph.at(node)) {
    if (explored.at(next_node)) {
      continue;
    }

    dfs(graph, next_node);
  }
}

int main() {
  int64_t N;
  int64_t M;
  std::cin >> N >> M;

  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a;
    int64_t b;
    std::cin >> a >> b;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }

  explored.assign(N, false);
  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    if (explored.at(i)) {
      continue;
    }

    dfs(graph, i);
    count++;
  }

  std::cout << count << std::endl;

  return 0;
}
