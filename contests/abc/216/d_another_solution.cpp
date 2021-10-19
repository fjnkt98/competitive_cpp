#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> graph(N);
  std::vector<int64_t> indegree(N, 0);
  for (int64_t i = 0; i < M; i++) {
    int64_t k;
    std::cin >> k;
    int64_t a;
    std::cin >> a;
    for (int64_t j = 1; j < k; j++) {
      int64_t b;
      std::cin >> b;
      graph.at(a - 1).push_back(b - 1);

      if (indegree.at(b - 1) == 0) indegree.at(b - 1) = 1;
      else indegree.at(b - 1)++;
      a = b;
    }
  }

  std::vector<int64_t> sorted_nodes;
  std::queue<int64_t> candidate;
  for (int64_t i = 0; i < N; i++) {
    if (indegree.at(i) == 0) {
      candidate.push(i);
    }
  }

  while (!candidate.empty()) {
    int64_t node = candidate.front();
    candidate.pop();

    sorted_nodes.push_back(node);
    for (int64_t next_node : graph.at(node)) {
      indegree.at(next_node)--;
      if (indegree.at(next_node) == 0) {
        candidate.push(next_node);
      }
    }
  }

  if (static_cast<int64_t>(sorted_nodes.size()) == N) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
