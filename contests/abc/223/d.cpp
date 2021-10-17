#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <queue>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> graph(N);
  std::vector<int64_t> indegree(N, 0);
  for (int64_t i = 0; i < M ; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    graph.at(a - 1).push_back(b - 1);
    indegree.at(b - 1)++;
  }

  std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> heap;
  for (int64_t i = 0; i < N; i++) {
    if (indegree.at(i) == 0) {
      heap.push(i);
    }
  }

  std::vector<int64_t> answer;
  while (!heap.empty()) {
    int64_t node = heap.top();
    heap.pop();

    answer.push_back(node);
    for (int64_t next_node : graph.at(node)) {
      indegree.at(next_node)--;
      if (indegree.at(next_node) == 0) {
        heap.push(next_node);
      }
    }
  }

  if (static_cast<int64_t>(answer.size()) == N) {
    for (int64_t i = 0; i < N; i++) {
      if (i) std::cout << " ";
      std::cout << answer.at(i) + 1;
    }
    std::cout << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }

  return 0;
}
