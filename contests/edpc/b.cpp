#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> h(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> h.at(i);
  }

  std::vector<int64_t> dp(N, 1LL << 60);
  dp.at(0) = 0;

  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 1; j <= K; j++) {
      if (i + j < N) {
        dp.at(i + j) = std::min(dp.at(i + j), dp.at(i) + std::abs(h.at(i) - h.at(i + j))); }
    }
  }

  std::cout << dp.at(N - 1) << std::endl;

  return 0;
}
