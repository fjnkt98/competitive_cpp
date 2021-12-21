#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, W;
  std::cin >> N >> W;
  std::vector<int64_t> v(N + 1);
  std::vector<int64_t> w(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> v.at(i) >> w.at(i);
  }

  std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(W + 1, 0));
  for (int64_t i = 1; i <= N; i++) {
    for (int64_t j = 0; j <= W; j++) {
      dp.at(i).at(j) = dp.at(i - 1).at(j);

      if (j - w.at(i) >= 0) {
        dp.at(i).at(j) = std::max(dp.at(i).at(j), dp.at(i - 1).at(j - w.at(i)) + v.at(i));
      }
    }
  }

  std::cout << dp.at(N).at(W) << std::endl;

  return 0;
}
