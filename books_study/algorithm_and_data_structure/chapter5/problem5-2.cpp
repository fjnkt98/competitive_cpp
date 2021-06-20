/*
 * Solving "Partial Sum Problem" by using DP
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

int main() {
  int64_t N;
  int64_t W;
  std::cin >> N >> W;

  std::vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  // DP table
  std::vector<std::vector<bool>> dp(N + 1, std::vector<bool>(W + 1, false));

  // DP initial condition
  dp.at(0).at(0) = true;

  // DP loop
  for (int64_t i = 0; i < N; i++) {
    for (int64_t w = 0; w <= W; w++) {
      // When choosing i-th element
      if (w - a.at(i) >= 0) {
        if (dp.at(i).at(w - a.at(i))) {
          dp.at(i + 1).at(w) = true;
        }
      } 
      // When don't choose i-th element
      if (dp.at(i).at(w)) {
        dp.at(i + 1).at(w) = true;
      }
    }
  }

  // Output the answer
  if (dp.at(N).at(W)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
