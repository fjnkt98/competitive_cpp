/*
 * Finding s-t path in the graph solving by using DFS
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
  int64_t s;
  int64_t t;
  std::cin >> N >> M >> s >> t;

  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a;
    int64_t b;
    std::cin >> a >> b;
    graph.at(a).push_back(b);
  }

  // Search the graph with s as starting point
  explored.assign(N, false);
  dfs(graph, s);

  if (explored.at(t)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
