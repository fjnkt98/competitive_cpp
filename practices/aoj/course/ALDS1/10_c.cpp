#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::pair<std::string, std::string>> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::string X, Y;
    std::cin >> X >> Y;

    A.at(i) = std::make_pair(X, Y);
  }

  for (auto& a : A) {
    std::string X = a.first;
    std::string Y = a.second;

    std::vector<std::vector<int64_t>> dp(X.size() + 1, std::vector<int64_t>(Y.size() + 1, 0));
    for (int64_t i = 1; i <= X.size(); i++) {
      for (int64_t j = 1; j <= Y.size(); j++) {
        if (X.at(i - 1) == Y.at(j - 1)) {
          dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
        } else {
          dp.at(i).at(j) = std::max(dp.at(i - 1).at(j), dp.at(i).at(j - 1));
        }
      }

    }
    std::cout << dp.at(X.size()).at(Y.size()) << std::endl;
  }

  return 0;
}
