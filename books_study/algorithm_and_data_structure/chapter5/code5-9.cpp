/*
 * Solving "Interval Split Problem" by using DP
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

template<class T> void choose_min(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<std::vector<int64_t>> cost(N + 1, std::vector<int64_t>(N + 1));

  for (int64_t i = 0; i < N + 1; i++) {
    for (int64_t j = 0; j < N + 1; j++) {
      std::cin >> cost.at(i).at(j);
    }
  }

  // Table for DP
  std::vector<int64_t> dp(N + 1, INT_MAX);

  // Initial condition
  dp.at(0) = 0;

  // DP loop
  for (int64_t i = 0; i <= N; i++) {
    for (int64_t j = 0; j < i; j++) {
      choose_min(dp.at(i), dp.at(j) + cost.at(j).at(i));
    }
  }

  std::cout << dp.at(N) << std::endl;

  return 0;
}
