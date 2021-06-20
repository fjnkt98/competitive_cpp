/*
 * Solving "Frog Problem" by using Dynamic Programing(DP)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> h(N);
  for(int64_t i = 0; i < N; i++) {
    std::cin >> h.at(i);
  }

  // Table of Dynamic Programing(DP)
  std::vector<int64_t> dp(N, INT_MAX);

  // Initial condition
  dp.at(0) = 0;

  for (int64_t i = 1; i < N; i++) {
    if (i == 1) {
      dp.at(i) = std::abs(h.at(i) - h.at(i - 1));
    } else {
      dp.at(i) = std::min(
          dp.at(i - 1) + std::abs(h.at(i) - h.at(i - 1)),
          dp.at(i - 2) + std::abs(h.at(i) - h.at(i - 2))
          );
    }
  }

  std::cout << dp.at(N - 1) << std::endl;

  return 0;
}
