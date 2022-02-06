#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> c(M + 1);
  for (int64_t i = 1; i <= M; i++) {
    std::cin >> c.at(i);
  }

  std::vector<std::vector<int64_t>> dp(M + 1,
                                       std::vector<int64_t>(N + 1, 1LL << 60));

  dp.at(0).at(0) = 0;
  for (int64_t i = 1; i <= M; i++) {
    for (int64_t j = 0; j <= N; j++) {
      dp.at(i).at(j) = std::min(dp.at(i).at(j), dp.at(i - 1).at(j));

      if (j - c.at(i) >= 0) {
        dp.at(i).at(j) = std::min(dp.at(i).at(j), dp.at(i).at(j - c.at(i)) + 1);
      }
    }
  }

  std::cout << dp.at(M).at(N) << std::endl;

  return 0;
}