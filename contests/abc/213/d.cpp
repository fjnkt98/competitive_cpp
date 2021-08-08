#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>

void dfs(int64_t current_node, int64_t previous_node,
        std::vector<std::vector<int64_t>>& graph, std::vector<int64_t>& history)
{
  history.push_back(current_node);
  for (int64_t x : graph.at(current_node)) {
    if (x != previous_node) {
      dfs(x, current_node, graph, history);
      history.push_back(current_node);
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

  for (int64_t i = 0; i < N; i++) {
    std::sort(graph.at(i).begin(), graph.at(i).end());
  }

  std::vector<int64_t> history;
  dfs(0, -1, graph, history);
  for (size_t i = 0; i < history.size(); i++) {
    if (i) std::cout << " ";
    std::cout << history.at(i) + 1;
  }
  std::cout << std::endl;

  return 0;
}
