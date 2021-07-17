/*
 * Implementation of Floyd-Warshall Method
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdint>

int main() {
  int64_t N, M;
  std::cin >> N >> M;

  // Dynamic Programing Array
  std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(N, INT64_MAX));
  // DP initial condition
  for (int64_t i = 0; i < M; i++) {
    int64_t a, b, w;
    std::cin >> a >> b >> w;
    dp.at(a).at(b) = w;
  }
  for (int64_t i = 0; i < N; i++) {
    dp.at(i).at(i) = 0;
  }

  // DP transition
  for (int64_t k = 0; k < N; k++) {
    for (int64_t i = 0; i < N; i++) {
      for (int64_t j = 0; j < N; j++) {
        dp.at(i).at(j) = std::min(dp.at(i).at(j),dp.at(i).at(k) + dp.at(k).at(j));
      }
    }
  }

  // If dp.at(i).at(i) < 0 then the graph has negative cycle
  bool exist_negative_cycle = false;
  for (int64_t i = 0; i < N; i++) {
    if (dp.at(i).at(i) < 0) {
      exist_negative_cycle = true;
    }
  }

  if (exist_negative_cycle) {
    std::cout << "NEGATIVE CYCLE" << std::endl;
  } else {
    for (int64_t i = 0; i < N; i++) {
      for (int64_t j = 0; j < N; j++) {
        if (j) {
          std::cout << " ";
        }
        if (dp.at(i).at(j) < INT64_MAX / 2) {
          std::cout << dp.at(i).at(j);
        } else {
          std::cout << "INF" << std::endl;
        }
      }
    }
  }
}
