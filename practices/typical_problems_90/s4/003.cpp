#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

std::vector<int64_t> bfs(std::vector<std::vector<int64_t>>& graph, int64_t start_node) {
  std::queue<int64_t> candidate;
  std::vector<int64_t> distance(graph.size(), -1);

  distance.at(start_node) = 0;
  candidate.push(start_node);

  while (!candidate.empty()) {
    int64_t current_node = candidate.front();
    candidate.pop();

    for (int64_t next_node : graph.at(current_node)) {
      if (distance.at(next_node) == -1) {
        distance.at(next_node) = distance.at(current_node) + 1;
        candidate.push(next_node);
      }
    }
  }

  return distance;
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

  std::vector<int64_t> distance = bfs(graph, 0);
  int64_t left_end_node = std::distance(distance.begin(),
                                        std::max_element(distance.begin(), distance.end()));

  distance = bfs(graph, left_end_node);
  int64_t max_distance = *std::max_element(distance.begin(), distance.end());

  std::cout << max_distance + 1 << std::endl;
  return 0;
}
