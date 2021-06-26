/*
 * Bipartite Graph Judgement
 */

#include <iostream>
#include <vector>

// For i-th node,
// "color.at(i) == 1" indicates that the node is black,
// "color.at(i) == 0" indicates that the node is white,
// "color.at(i) == -1" indicates that the node haven't been explored.
std::vector<int64_t> color;

bool dfs(const std::vector<std::vector<int64_t>>& graph, int64_t node, int64_t current_color = 0) {
  color.at(node) = current_color;

  for (auto next_node : graph.at(node)) {
    // When the adjacent node's color has been determined
    if (color.at(next_node) != -1) {
      // It is not bipartite graph if same color is adjacent
      if (color.at(next_node) == current_color) {
        return false;
      }

      // Don't search the explored node
      continue;
    }

    // Recursive search
    if (!dfs(graph, next_node, (1 - current_color))) {
      return false;
    }
  }

  return true;
}

int main() {
  int64_t N;
  int64_t M;
  std::cin >> N >> M;

  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a;
    int64_t b;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }

  color.assign(N, -1);
  bool is_bipartite = true;

  for (int64_t i = 0; i < N; i++) {
    if (color.at(i) != -1) {
      continue;
    }

    if (!dfs(graph, i)) {
      is_bipartite = false;
    }
  }

  if (is_bipartite) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
