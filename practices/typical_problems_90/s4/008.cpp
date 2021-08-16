#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::string S;
  std::cin >> N >> S;

  const std::string atcoder = "atcoder";
  const int64_t mod = 1000000007;

  std::vector<std::vector<int64_t>> dp(atcoder.size() + 1, std::vector<int64_t>(N + 1));
  dp.at(0).assign(N + 1, 1);

  for (int64_t i = 1; i < atcoder.size() + 1; i++) {
    for (int64_t j = 1; j < N + 1; j++) {
      if (atcoder.at(i - 1) == S.at(j - 1)) {
        dp.at(i).at(j) = dp.at(i).at(j - 1) + dp.at(i - 1).at(j);
      } else {
        dp.at(i).at(j) = dp.at(i).at(j - 1);
      }

      dp.at(i).at(j) = dp.at(i).at(j) % mod;
    }
  }

  std::cout << dp.at(atcoder.size()).at(N) << std::endl;

  return 0;
}
