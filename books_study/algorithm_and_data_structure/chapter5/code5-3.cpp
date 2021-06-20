/*
 * Solving "Frog Problem" by using DP with Relaxation
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

/* Relaxation Function */
template<class T> void choose_min(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

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

  // Case of i = 1
  choose_min(dp.at(1), (dp.at(0) + std::abs(h.at(1) - h.at(0))));
  for (int64_t i = 2; i < N; i++) {
    // Relaxation
    choose_min(dp.at(i), (dp.at(i - 1) + std::abs(h.at(i) - h.at(i - 1))));
    choose_min(dp.at(i), (dp.at(i - 2) + std::abs(h.at(i) - h.at(i - 2))));
  }

  std::cout << dp.at(N - 1) << std::endl;

  return 0;
}
