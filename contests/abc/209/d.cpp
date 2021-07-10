#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
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
  int64_t N, Q;
  std::cin >> N >> Q;

  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N - 1; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    // Make 0=index
    graph.at(a - 1).push_back(b - 1);
    graph.at(b - 1).push_back(a - 1);
  }

  std::vector<std::pair<int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t c, d;
    std::cin >> c >> d;
    // Make 0-index
    query.at(i) = std::make_pair(c - 1, d - 1);
  }

  // Start calculation
  std::vector<int64_t> distance = bfs(graph, 0);

  for (int64_t i = 0; i < Q; i++) {
    if (distance.at(query.at(i).first) % 2 == distance.at(query.at(i).second) % 2) {
      std::cout << "Town" << std::endl;
    } else {
      std::cout << "Road" << std::endl;
    }
  }

  return 0;
}
