/*
 * Implement Depth-First Search(DFS) algorithm using recursive function
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

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
    int64_t from;
    int64_t to;
    std::cin >> from >> to;
    graph.at(from).push_back(to);
  }

  explored.assign(N, false);
  for(int64_t v = 0; v < N; v++) {
    if (explored.at(v)) {
      continue;
    }
    dfs(graph, v);
  }
}
