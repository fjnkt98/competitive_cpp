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

  std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(10, 0));
  dp.at(0).at(A.at(0)) = 1;
  for (int64_t i = 1; i < N; i++) {
    for (int64_t j = 0; j < 10; j++) {
      if (dp.at(i - 1).at(j) > 0) {
        dp.at(i).at((j + A.at(i)) % 10) += dp.at(i - 1).at(j);
        dp.at(i).at((j * A.at(i)) % 10) += dp.at(i - 1).at(j);

        dp.at(i).at((j + A.at(i)) % 10) = dp.at(i).at((j + A.at(i)) % 10) % 998244353;
        dp.at(i).at((j * A.at(i)) % 10) = dp.at(i).at((j * A.at(i)) % 10) % 998244353;
      }
    }
  }

  for (int64_t i = 0; i < 10; i++) {
    std::cout << dp.at(N - 1).at(i) << std::endl;
  }

  return 0;
}
