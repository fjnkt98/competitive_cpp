#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  int64_t R, S, P;
  std::cin >> R >> S >> P;
  std::string T;
  std::cin >> T;

  std::vector<std::string> group(K);
  for (int64_t i = 0; i < N; i++) {
    group.at(i % K).push_back(T.at(i));
  }

  int64_t answer = 0;
  for (auto g : group) {
    std::vector<std::vector<int64_t>> dp(g.size() + 1, std::vector<int64_t>(3, 0));

    for (size_t i = 1; i <= g.size(); i++) {
      switch (g.at(i - 1)) {
        case 'r':
          dp.at(i).at(0) = std::max(dp.at(i - 1).at(1), dp.at(i - 1).at(2));
          dp.at(i).at(1) = std::max(dp.at(i - 1).at(0), dp.at(i - 1).at(2));
          dp.at(i).at(2) = std::max(dp.at(i - 1).at(0), dp.at(i - 1).at(1)) + P;
          break;
        case 's':
          dp.at(i).at(0) = std::max(dp.at(i - 1).at(1), dp.at(i - 1).at(2)) + R;
          dp.at(i).at(1) = std::max(dp.at(i - 1).at(0), dp.at(i - 1).at(2));
          dp.at(i).at(2) = std::max(dp.at(i - 1).at(0), dp.at(i - 1).at(1));
          break;
        case 'p':
          dp.at(i).at(0) = std::max(dp.at(i - 1).at(1), dp.at(i - 1).at(2));
          dp.at(i).at(1) = std::max(dp.at(i - 1).at(0), dp.at(i - 1).at(2)) + S;
          dp.at(i).at(2) = std::max(dp.at(i - 1).at(0), dp.at(i - 1).at(1));
          break;
      }
    }

    answer += *std::max_element(dp.at(g.size()).begin(), dp.at(g.size()).end());
  }

  std::cout << answer << std::endl;

  return 0;
}
