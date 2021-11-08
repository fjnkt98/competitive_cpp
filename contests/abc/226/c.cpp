#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

void dfs(std::vector<std::vector<int64_t>>& graph,
            std::vector<bool>& acquired,
            std::vector<int64_t>& T,
            int64_t& total_time,
            int64_t current_node)
{
  for (auto next_node : graph.at(current_node)) {
    if (acquired.at(next_node) == false) {
      dfs(graph, acquired, T, total_time, next_node);
    }
  }
  acquired.at(current_node) = true;
  total_time += T.at(current_node);
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> T(N);
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t t, k;
    std::cin >> t >> k;
    T.at(i) = t;
    for (int64_t j = 0; j < k; j++) {
      int64_t a;
      std::cin >> a;
      graph.at(i).push_back(a - 1);
    }

    std::sort(graph.at(i).begin(), graph.at(i).end(), std::greater<int64_t>{});
  }

  std::vector<bool> acquired(N, false);
  int64_t answer = 0;
  dfs(graph, acquired, T, answer, N - 1);

  std::cout << answer << std::endl;

  return 0;
}
