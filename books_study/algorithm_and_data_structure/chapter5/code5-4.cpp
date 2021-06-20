/*
 * Solving "Frog Problem" by using push-based DP
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

  for (int64_t i = 0; i < N; i++) {
    if (i + 1 < N) {
      choose_min(dp.at(i + 1), (dp.at(i) + std::abs(h.at(i + 1) - h.at(i))));
    }

    if (i + 2 < N) {
      choose_min(dp.at(i + 2), (dp.at(i) + std::abs(h.at(i + 2) - h.at(i))));
    }
  }

  std::cout << dp.at(N - 1) << std::endl;

  return 0;
}
