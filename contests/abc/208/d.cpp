#include <iostream>
#include <vector>
#include <algorithm>

const int64_t INF = 1LL << 60;

int main() {
  int64_t N, M;
  std::cin >> N >> M;

  std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(N, INF));
  for (int64_t i = 0; i < M; i++) {
    int64_t from, to, weight;
    std::cin >> from >> to >> weight;
    dp.at(from - 1).at(to - 1) = weight;
  }
  for (int64_t i = 0; i < N; i++) {
    dp.at(i).at(i) = 0;
  }

  int64_t answer = 0;
  for (int64_t k = 0; k < N; k++) {
    for (int64_t i = 0; i < N; i++) {
      for (int64_t j = 0; j < N; j++) {
        dp.at(i).at(j) = std::min(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k).at(j));
        if (dp.at(i).at(j) < INF) {
          answer += dp.at(i).at(j);
        }
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
