#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

void dfs(std::vector<std::vector<int64_t>>& graph, std::vector<int64_t>& color,
         int64_t current_node, int64_t current_color)
{
  color.at(current_node) = current_color;
  for (int64_t next_node : graph.at(current_node)) {
    if ((color.at(next_node)) == -1) {
      dfs(graph, color, next_node, 1 - current_color);
    }
  }
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N - 1; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    graph.at(a - 1).push_back(b - 1);
    graph.at(b - 1).push_back(a - 1);
  }

  std::vector<int64_t> color(N, -1);
  dfs(graph, color, 0, 0);

  std::vector<int64_t> black_node;
  std::vector<int64_t> white_node;
  for (int64_t i = 0; i < N; i++) {
    if (color.at(i) == 0) black_node.push_back(i);
    else white_node.push_back(i);
  }

  if (black_node.size() > white_node.size()) {
    for (int64_t i = 0; i < N / 2; i++) {
      if (i) std::cout << " ";
      std::cout << black_node.at(i) + 1;
    }
    std::cout << std::endl;
  } else {
    for (int64_t i = 0; i < N / 2; i++) {
      if (i) std::cout << " ";
      std::cout << white_node.at(i) + 1;
    }
    std::cout << std::endl;
  }

  return 0;
}
