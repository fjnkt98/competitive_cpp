#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int64_t>>& graph, std::vector<int64_t>& count,
         int64_t previous_node, int64_t current_node) {
  for (int64_t next_node : graph.at(current_node)) {
    if (next_node == previous_node) continue;
    count.at(next_node) += count.at(current_node);
    dfs(graph, count, current_node, next_node);
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
  std::vector<int64_t> count(N);
  for (int64_t i = 0; i < Q; i++) {
    int64_t p, x;
    std::cin >> p >> x;
    count.at(p - 1) += x;
  }

  dfs(graph, count, -1, 0);

  for (int64_t i = 0; i < N; i++) {
    if (i) std::cout << " ";
    std::cout << count.at(i);
  }
  std::cout << std::endl;

  return 0;
}