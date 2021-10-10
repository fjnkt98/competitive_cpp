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
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> B.at(i);
  }

  std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(30001, 0));
  dp.at(0).at(0) = 1;

  std::vector<int64_t> cumsum(3001, 0);

  for (int64_t i = 0; i < N; i++) {
    cumsum.at(0) = dp.at(i).at(0);
    for (int64_t j = 1; j <= 3000; j++) {
      cumsum.at(j) = (cumsum.at(j - 1) + dp.at(i).at(j)) % 998244353;
    }
    for (int64_t j = A.at(i); j <= B.at(i); j++) {
      dp.at(i + 1).at(j) += cumsum.at(j) % 998244353;
    }
  }

  int64_t answer = 0;
  for (int64_t i = 0; i <= 3000; i++) {
    answer += dp.at(N).at(i);
    answer = answer % 998244353;
  }

  std::cout << answer << std::endl;

  return 0;
}
