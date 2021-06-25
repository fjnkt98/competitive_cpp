/*
 * Fundamental Breadth-First Search
 */

#include <iostream>
#include <vector>
#include <queue>

std::vector<int64_t> bfs(const std::vector<std::vector<int64_t>>& graph, int64_t start_node) {
  int64_t N = static_cast<int64_t>(graph.size());

  std::vector<int64_t> distance(N, -1);
  std::queue<int64_t> candidate;

  // Initial condition
  distance.at(start_node) = 0;
  candidate.push(start_node);

  while (!candidate.empty()) {
    int64_t node = candidate.front();
    candidate.pop();

    for (int64_t x : graph.at(node)) {
      if (distance.at(x) != -1) {
        continue;
      }

      distance.at(x) = distance.at(node) + 1;
      candidate.push(x);
    }
  }

  return distance;
}

int main() {
  int64_t N;
  int64_t M;
  std::cin >> N >> M;

  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a;
    int64_t b;

    std::cin >> a >> b;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }

  std::vector<int64_t> distance = bfs(graph, 0);

  for (int64_t i = 0; i < N; i++) {
    std::cout << i << ": " << distance.at(i) << std::endl;
  }

  return 0;
}
