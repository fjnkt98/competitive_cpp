#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void dfs(std::vector<std::vector<std::pair<int64_t, int64_t>>>& graph,
         std::vector<int64_t>& color,
         int64_t previous_node,
         int64_t current_node,
         int64_t previous_color)
{
  int64_t current_color = 0;

  for (auto next : graph.at(current_node)) {
    int64_t next_node = next.first;
    int64_t next_index = next.second;

    if (next_node != previous_node && color.at(next_index) == -1) {
      current_color++;
      if (current_color == previous_color) {
        current_color++;
      }

      color.at(next_index) = current_color;
      dfs(graph, color, current_node, next_node, current_color);
    }
  }
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(N);
  for (int64_t i = 0; i < N - 1; i++) {
    int64_t a, b;
    std::cin >> a >> b;

    graph.at(a - 1).push_back(std::make_pair(b - 1, i));
    graph.at(b - 1).push_back(std::make_pair(a - 1, i));
  }

  int64_t color_variety = 0;
  for (int64_t i = 0; i < N; i++) {
    color_variety = std::max(color_variety, static_cast<int64_t>(graph.at(i).size()));
  }

  std::vector<int64_t> color(N - 1, -1);

  dfs(graph, color, -1, 0, 0);

  std::cout << color_variety << std::endl;
  for (auto c : color) {
    std::cout << c << std::endl;
  }

  return 0;
}
