#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

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
  }

  std::vector<bool> reachable(N, false);
  reachable.at(N - 1) = true;
  std::queue<int64_t> candidate;
  candidate.push(N - 1);

  while (!candidate.empty()) {
    int64_t node = candidate.front();
    candidate.pop();

    for (int64_t next_node : graph.at(node)) {
      if (reachable.at(next_node)) continue;
      reachable.at(next_node) = true;
      candidate.push(next_node);
    }
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    if (reachable.at(i)) {
      answer += T.at(i);
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
