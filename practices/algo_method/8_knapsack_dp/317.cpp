#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t T;
  std::cin >> T;
  std::vector<std::vector<int64_t>> g(T, std::vector<int64_t>(T));
  for (int64_t i = 0; i < T; i++) {
    for (int64_t j = 0; j < T; j++) {
      std::cin >> g.at(i).at(j);
    }
  }

  std::vector<int64_t> dp(T + 2);
  dp.at(0) = 0;

  for (int64_t t = 1; t <= T + 1; t++) {
    for (int64_t i = 0; i < t; i++) {
      for (int64_t j = i + 1; j < t; j++) {
        dp.at(t) = std::max(dp.at(t), dp.at(i) + g.at(i).at(j - 1));
      }
    }
  }

  std::cout << dp.at(T + 1) << std::endl;

  return 0;
}