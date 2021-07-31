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
    // Make 0-index
    graph.at(a - 1).push_back(b - 1);
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    std::vector<bool> explored(N, false);
    std::queue<int64_t> candidate;

    explored.at(i) = true;
    candidate.push(i);

    while (!candidate.empty()) {
      int64_t v = candidate.front();
      candidate.pop();

      for (int64_t x : graph.at(v)) {
        if (!explored.at(x)) {
          explored.at(x) = true;
          candidate.push(x);
        }
      }
    }

    for (bool e : explored) {
      if (e) {
        count++;
      }
    }
  }

  std::cout << count << std::endl;

  return 0;
}
