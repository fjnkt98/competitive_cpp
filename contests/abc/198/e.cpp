#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void dfs(std::vector<std::vector<int64_t>>& graph,
        std::vector<int64_t>& color,
        std::vector<int64_t>& count,
        std::vector<int8_t>& is_good_node,
        int64_t current_node,
        int64_t previous_node)
{
  if (count.at(color.at(current_node)) == 0) is_good_node.at(current_node) = 1;
  count.at(color.at(current_node))++;

  for (int64_t x : graph.at(current_node)) {
    if (x != previous_node) {
      dfs(graph, color, count, is_good_node, x, current_node);
    }
  }

  count.at(color.at(current_node))--;
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> color(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> color.at(i);
  }
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N - 1; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    graph.at(a - 1).push_back(b - 1);
    graph.at(b - 1).push_back(a - 1);
  }

  std::vector<int8_t> is_good_node(N, 0);
  std::vector<int64_t> count(100001, 0);

  dfs(graph, color, count, is_good_node, 0, -1);

  for (int64_t i = 0; i < N; i++) {
    if (is_good_node.at(i) == 1) {
      std::cout << i + 1 << std::endl;
    }
  }

  return 0;
}
