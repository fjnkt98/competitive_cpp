#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

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

  std::vector<int64_t> distance(N, -1);
  std::queue<int64_t> candidate;
  candidate.push(0);
  distance.at(0) = 0;

  while (!candidate.empty()) {
    int64_t node = candidate.front();
    candidate.pop();

    for (auto next_node : graph.at(node)) {
      if (distance.at(next_node) == -1) {
        distance.at(next_node) = distance.at(node) + 1;
        candidate.push(next_node);
      }
    }
  }

  for (int64_t i = 0; i < N; i++) {
    std::cout << i + 1 << " " << distance.at(i) << std::endl;
  }

  return 0;
}
