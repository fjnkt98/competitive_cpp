#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t a, b;
    std::cin >> a >> b;

    graph.at(a - 1).push_back(b - 1);
    graph.at(b - 1).push_back(a - 1);
  }

  bool ok = false;

  std::queue<int64_t> candidate;
  candidate.push(0);
  std::vector<int64_t> distance(N, -1);
  distance.at(0) = 0;

  while (!candidate.empty()) {
    int64_t node = candidate.front();
    candidate.pop();

    for (int64_t next_node : graph.at(node)) {
      if (distance.at(next_node) == -1) {
        distance.at(next_node) = distance.at(node) + 1;
        candidate.push(next_node);
      }
    }
  }

  if (distance.at(N - 1) == 2) {
    ok = true;
  }

  if (ok) {
    std::cout << "POSSIBLE" << std::endl;
  } else {
    std::cout << "IMPOSSIBLE" << std::endl;
  }

  return 0;
}
