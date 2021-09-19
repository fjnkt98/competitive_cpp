#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N, W;
  std::cin >> N >> W;
  std::vector<int64_t> w(N + 1);
  std::vector<int64_t> v(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> w.at(i) >> v.at(i);
  }

  int64_t V = std::accumulate(v.begin(), v.end(), static_cast<int64_t>(0));
  std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(V + 1, 1LL << 60));

  dp.at(0).at(0) = 0;
  for (int64_t i = 1; i <= N; i++) {
    for (int64_t j = 0; j <= V; j++) {
      dp.at(i).at(j) = dp.at(i - 1).at(j);

      if (j - v.at(i) >= 0) {
        dp.at(i).at(j) = std::min(dp.at(i).at(j), dp.at(i - 1).at(j - v.at(i)) + w.at(i));
      }
    }
  }

  int64_t answer = 0;
  for (int64_t i = 1; i <= N; i++) {
    for (int64_t j = 1; j <= V; j++) {
      if (dp.at(i).at(j) <= W) {
        answer = std::max(answer, j);
      }
    }
  }

  std::cout << answer << std::endl;
}
