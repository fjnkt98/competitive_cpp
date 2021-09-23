#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S, T;
  std::cin >> S >> T;

  std::vector<std::vector<int64_t>> dp(S.size() + 1, std::vector<int64_t>(T.size()  + 1));
  for (int64_t i = 1; i <= static_cast<int64_t>(S.size()); i++) {
    for (int64_t j = 1; j <= static_cast<int64_t>(T.size()); j++) {
      if (S.at(i - 1) == T.at(j - 1)) {
        dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
      } else {
        dp.at(i).at(j) = std::max(dp.at(i).at(j - 1), dp.at(i - 1).at(j));
      }
    }
  }

  std::string answer;
  int64_t i = static_cast<int64_t>(S.size());
  int64_t j = static_cast<int64_t>(T.size());
  while (static_cast<int64_t>(answer.size()) < dp.at(S.size()).at(T.size())) {
    if (S.at(i - 1) == T.at(j - 1)) {
      answer.push_back(S.at(i - 1));
      i--;
      j--;
    } else if (dp.at(i).at(j) == dp.at(i - 1).at(j)){
      i--;
    } else {
      j--;
    }
  }

  std::reverse(answer.begin(), answer.end());

  std::cout << answer << std::endl;

  return 0;
}
