#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void tp_sort(std::vector<std::vector<int64_t>>& graph,
            std::vector<bool>& explored,
            std::vector<int64_t>& order,
            int64_t node)
{
  explored.at(node) = true;
  for (auto next_node : graph.at(node)) {
    if (!explored.at(next_node)) {
      tp_sort(graph, explored, order, next_node);
    }
  }

  order.push_back(node);
}

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t x, y;
    std::cin >> x >> y;

    graph.at(x - 1).push_back(y - 1);
  }

  std::vector<int64_t> order;
  std::vector<bool> explored(N, false);
  for (int64_t i = 0; i < N; i++) {
    if (!explored.at(i)) {
      tp_sort(graph, explored, order, i);
    }
  }

  std::reverse(order.begin(), order.end());

  std::vector<int64_t> dp(N, 0);
  for (auto i : order) {
    for (auto v : graph.at(i)) {
      dp.at(v) = std::max(dp.at(v), dp.at(i) + 1);
    }
  }

  std::cout << *std::max_element(dp.begin(), dp.end()) << std::endl;

  return 0;
}
