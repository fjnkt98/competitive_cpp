/*
 * Solving "Edit Distance Problem" by using DP
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

template<class T> void choose_min(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

int main() {
  std::string S;
  std::string T;
  std::cin >> S >> T;

  // Talbe for DP
  std::vector<std::vector<int64_t>> dp(S.size() + 1, std::vector<int64_t>(T.size() + 1, INT_MAX));

  // Initial condition
  dp.at(0).at(0) = 0;

  // DP loop
  for (int64_t i = 0; i <= S.size(); i++) {
    for (int64_t j = 0; j <= T.size(); j++) {
      // Change operation
      if (i > 0 && j > 0) {
        if (S.at(i - 1) == T.at(j - 1)) {
          choose_min(dp.at(i).at(j), dp.at(i - 1).at(j - 1));
        } else {
          choose_min(dp.at(i).at(j), dp.at(i - 1).at(j - 1) + 1);
        }
      }

      // Delete operation
      if (i > 0) {
        choose_min(dp.at(i).at(j), dp.at(i - 1).at(j) + 1);
      }

      // Insert operation
      if (j > 0) {
        choose_min(dp.at(i).at(j), dp.at(i).at(j - 1) + 1);
      }
    }
  }

  std::cout << dp.at(S.size()).at(T.size()) << std::endl;

  return 0;
}
