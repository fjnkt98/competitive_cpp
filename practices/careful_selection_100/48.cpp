#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <cmath>

int main() {
  std::vector<int64_t> answer;
  while (true) {
    int64_t N;
    std::cin >> N;

    if (N == 0) break;

    std::vector<int64_t> W(N);
    for (int64_t i = 0; i < N; i++) {
      std::cin >> W.at(i);
    }

    std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(N + 2, 0));
    for (int64_t i = 0; i < N - 1; i++) {
      if (std::abs(W.at(i) - W.at(i + 1)) <= 1) {
        dp.at(i).at(i + 2) = 2;
      }
    }

    for (int64_t l = 2; l <= N; l++) {
      for (int64_t i = 0; i <= N - l; i++) {
        int64_t j = i + l;

        if (dp.at(i + 1).at(j - 1) == l - 2 &&
            std::abs(W.at(i) - W.at(j - 1)) <= 1) {
          dp.at(i).at(j) = std::max(dp.at(i).at(j), dp.at(i + 1).at(j - 1) + 2);
        }

        for (int64_t k = i + 1; k < j; k++) {
          dp.at(i).at(j) =
              std::max(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k).at(j));
        }
      }
    }

    answer.push_back(dp.at(0).at(N));
  }

  for (auto a : answer) {
    std::cout << a << std::endl;
  }

  return 0;
}