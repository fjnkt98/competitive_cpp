#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  const std::string chokudai = "chokudai";
  const int64_t mod = 1000000007;

  std::vector<std::vector<int64_t>> dp(chokudai.size() + 1,
      std::vector<int64_t>(S.size() + 1, 0));

  dp.at(0).assign(S.size() + 1, 1);

  for (int64_t i = 1; i <= chokudai.size(); i++) {
    for (int64_t j = 1; j <= S.size(); j++) {
      if (chokudai.at(i - 1) == S.at(j - 1)) {
        dp.at(i).at(j) = dp.at(i).at(j - 1) + dp.at(i - 1).at(j - 1);
      } else {
        dp.at(i).at(j) = dp.at(i).at(j - 1);
      }

      dp.at(i).at(j) = dp.at(i).at(j) % mod;
    }
  }

  std::cout << dp.at(chokudai.size()).at(S.size()) << std::endl;

  return 0;
}
