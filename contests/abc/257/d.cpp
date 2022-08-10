#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <queue>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> X(N);
  std::vector<int64_t> Y(N);
  std::vector<int64_t> P(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> X.at(i) >> Y.at(i) >> P.at(i);
  }

  int64_t left = 0;
  int64_t right = 4000000001LL;

  while (right - left > 1) {
    int64_t mid = (left + right) / 2;

    bool ok = false;

    for (int64_t i = 0; i < N; i++) {
      std::vector<std::vector<int64_t>> graph(N);
      for (int64_t j = 0; j < N; j++) {
        for (int64_t k = 0; k < N; k++) {
          if (j == k) continue;
          if (P.at(j) * mid >=
              std::abs(X.at(j) - X.at(k)) + std::abs(Y.at(j) - Y.at(k))) {
            graph.at(j).push_back(k);
          }
        }
      }

      std::vector<int64_t> distance(N, -1);
      distance.at(i) = 0;
      std::queue<int64_t> candidate;
      candidate.push(i);

      while (!candidate.empty()) {
        int64_t node = candidate.front();
        candidate.pop();

        for (int64_t next_node : graph.at(node)) {
          if (distance.at(next_node) != -1) continue;
          candidate.push(next_node);
          distance.at(next_node) = distance.at(node) + 1;
        }
      }

      bool reachable = true;
      for (int64_t j = 0; j < N; j++) {
        if (distance.at(j) == -1) {
          reachable = false;
        }
      }

      ok |= reachable;
    }

    if (ok) {
      right = mid;
    } else {
      left = mid;
    }
  }

  std::cout << right << std::endl;

  return 0;
}