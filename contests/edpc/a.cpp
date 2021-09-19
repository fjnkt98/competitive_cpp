#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> h(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> h.at(i);
  }

  std::vector<int64_t> dp(N, 1LL << 60);
  dp.at(0) = 0;
  dp.at(1) = std::abs(h.at(1) - h.at(0));
  for (int64_t i = 2; i < N; i++) {
    dp.at(i) = std::min(dp.at(i - 1) + std::abs(h.at(i) - h.at(i - 1)),
                        dp.at(i - 2) + std::abs(h.at(i) - h.at(i - 2)));
  }

  std::cout << dp.at(N - 1) << std::endl;

  return 0;
}
