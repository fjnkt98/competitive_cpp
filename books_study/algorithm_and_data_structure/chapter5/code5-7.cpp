/*
 * Solving "Knapsack Problem" by using Dynamic Programing
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

/* Relaxation Function */
template<class T> void choose_max(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main() {
  int64_t N;
  int64_t W;
  std::cin >> N >> W;

  std::vector<int64_t> weight(N);
  std::vector<int64_t> value(N);

  for (int64_t i = 0; i < N; i++) {
    std::cin >> weight.at(i) >> value.at(i);
  }

  // Table for DP
  std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(W + 1, 0));

  // DP loop
  for (int64_t i = 0; i < N; i++) {
    for (int64_t w = 0; w <= W; w++) {
      // Case when choosing i-th item
      if (w - weight.at(i) >= 0) {
        choose_max(dp.at(i + 1).at(w), dp.at(i).at(w - weight.at(i)) + value.at(i));
      }
      // Case when don't choose i-th item
      choose_max(dp.at(i + 1).at(w), dp.at(i).at(w));
    }
  }

  std::cout << dp.at(N).at(W) << std::endl;

  return 0;
}
