#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, L;
  std::cin >> N >> L;

  std::vector<int64_t> dp(N + 1, 0);
  dp.at(0) = 1;
  dp.at(1) = 1;
  for (int64_t i = 2; i <= N; i++) {
    dp.at(i) = dp.at(i - 1);
    if ((i - L) >= 0) {
      dp.at(i) += dp.at(i - L);
    }
    dp.at(i) = dp.at(i) % 1000000007;
  }

  std::cout << dp.at(N) << std::endl;

  return 0;
}
