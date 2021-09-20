#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> p(N + 1);
  for (int64_t i = 1; i <= N ; i++) {
    std::cin >> p.at(i - 1) >> p.at(i);
  }

  std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(N + 1, 1LL << 60));
  for (int64_t i = 0; i <= N; i++) {
    dp.at(i).at(i) = 0;
  }

  for (int64_t l = 2; l <= N; l++) {
    for (int64_t i = 1; i <= N - l + 1; i++) {
      int64_t j = i + l - 1;
      for (int64_t k = i; k <= j - 1; k++) {
        dp.at(i).at(j) = std::min(dp.at(i).at(j),
            dp.at(i).at(k) + dp.at(k + 1).at(j) + p.at(i - 1) * p.at(k) * p.at(j));
      }
    }
  }

  std::cout << dp.at(1).at(N) << std::endl;

  return 0;
}
