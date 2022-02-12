#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(21, 0));
  dp.at(0).at(A.at(0)) = 1;

  for (int64_t i = 1; i < N - 1; i++) {
    for (int64_t j = 0; j <= 20; j++) {
      if (j + A.at(i) <= 20) {
        dp.at(i).at(j + A.at(i)) += dp.at(i - 1).at(j);
      }

      if (j - A.at(i) >= 0) {
        dp.at(i).at(j - A.at(i)) += dp.at(i - 1).at(j);
      }
    }
  }

  std::cout << dp.at(N - 2).at(A.back()) << std::endl;

  return 0;
}