/*
 * Topological Sort by using Depth-First Search(DFS) implemented by recursive function
 */

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<bool> explored;
std::vector<int64_t> topological_order;

void topological_sort(const std::vector<std::vector<int64_t>>& graph, int64_t node) {
  explored.at(node) = true;

  for (auto next_node : graph.at(node)) {
    if (explored.at(next_node)) {
      continue;
    }

    topological_sort(graph, next_node);
  }

  topological_order.push_back(node);
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
  }

  explored.assign(N, false);
  topological_order.clear();

  for (int64_t i = 0; i < N; i++) {
    if (explored.at(i)) {
      continue;
    }

    topological_sort(graph, i);
  }

  std::reverse(topological_order.begin(), topological_order.end());

  for(auto node : topological_order) {
    std::cout << node << " -> ";
  }
  std::cout << std::endl;

  return 0;

}
