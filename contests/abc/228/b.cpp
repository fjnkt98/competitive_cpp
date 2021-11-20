#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void dfs(std::vector<std::vector<int64_t>>& graph,
         std::vector<bool>& known,
         int64_t current_node,
         int64_t previous_node)
{
  known.at(current_node) = true;

  for (auto node : graph.at(current_node)) {
    if (known.at(node) == false) {
      dfs(graph, known, node, current_node);
    }
  }
}

int main() {
  int64_t N, X;
  std::cin >> N >> X;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a;
    std::cin >> a;

    graph.at(i).push_back(a - 1);
  }

  std::vector<bool> known(N, false);
  dfs(graph, known, X - 1, -1);

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    if (known.at(i)) answer++;
  }

  std::cout << answer << std::endl;

  return 0;
}
