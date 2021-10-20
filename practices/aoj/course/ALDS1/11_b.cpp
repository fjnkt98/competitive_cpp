#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void dfs(std::vector<std::vector<int64_t>>& graph,
        std::vector<bool>& explored,
        std::vector<int64_t>& d,
        std::vector<int64_t>& f,
        int64_t& time,
        int64_t node)
{
  explored.at(node) = true;
  time++;
  d.at(node) = time;

  for (int64_t next_node : graph.at(node)) {
    if (explored.at(next_node) == false) {
      dfs(graph, explored, d, f, time, next_node);
    }
  }

  time++;
  f.at(node) = time;
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t u, k;
    std::cin >> u >> k;
    for (int64_t j = 0; j < k; j++) {
      int64_t v;
      std::cin >> v;
      graph.at(u - 1).push_back(v - 1);
    }
  }

  for (int64_t i = 0; i < N; i++) {
    std::sort(graph.at(i).begin(), graph.at(i).end());
  }

  std::vector<bool> explored(N, false);
  std::vector<int64_t> d(N, -1);
  std::vector<int64_t> f(N, -1);

  int64_t time = 0;
  for (int64_t i = 0; i < N; i++) {
    if (explored.at(i) == false) {
      dfs(graph, explored, d, f, time, i);
    }
  }

  for (int64_t i = 0; i < N; i++) {
    std::cout << i + 1 << " " << d.at(i) << " " << f.at(i) << std::endl;
  }

  return 0;
}
