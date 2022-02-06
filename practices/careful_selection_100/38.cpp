#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::pair<std::string, std::string>> input(N);
  for (int64_t i = 0; i < N; i++) {
    std::string s, t;
    std::cin >> s >> t;
    input.at(i) = std::make_pair(s, t);
  }

  for (int64_t i = 0; i < N; i++) {
    std::string s = input.at(i).first;
    std::string t = input.at(i).second;

    std::vector<std::vector<int64_t>> dp(s.size() + 1,
                                         std::vector<int64_t>(t.size() + 1));
    for (int64_t i = 1; i <= s.size(); i++) {
      for (int64_t j = 1; j <= t.size(); j++) {
        if (s.at(i - 1) == t.at(j - 1)) {
          dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
        } else {
          dp.at(i).at(j) = std::max(dp.at(i - 1).at(j), dp.at(i).at(j - 1));
        }
      }
    }

    std::cout << dp.at(s.size()).at(t.size()) << std::endl;
  }

  return 0;
}