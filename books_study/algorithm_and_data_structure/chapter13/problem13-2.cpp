/*
 * Finding s-t path in the graph solving by using BFS
 */

#include <iostream>
#include <vector>
#include <queue>

std::vector<bool> bfs(const std::vector<std::vector<int64_t>>& graph, int64_t start_node) {
  // Get size of the graph
  int64_t N = static_cast<int64_t>(graph.size());

  // Array which stores if the node has been explored or not
  std::vector<bool> explored(N, false);
  // Candidate node for next search
  std::queue<int64_t> candidates;;

  // Initial condition
  explored.at(start_node) = true;
  candidates.push(start_node);

  while (candidates.empty()) {
    int64_t node = candidates.front();
    candidates.pop();

    for (int64_t x : graph.at(node)) {
      if (explored.at(node)) {
        continue;
      }

      explored.at(node) = true;
      candidates.push(x);
    }
  }

  return explored;
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

  std::vector<bool> explored = bfs(graph, s);

  if (explored.at(t)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
