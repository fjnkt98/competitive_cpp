#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t H, N;
  std::cin >> H >> N;
  std::vector<int64_t> A(N + 1);
  std::vector<int64_t> B(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }

  int64_t maximum_A = *std::max_element(A.begin(), A.end());
  int64_t HP = 100000;

  std::vector<std::vector<int64_t>> dp(N + 1,
                                       std::vector<int64_t>(HP + 1, 1LL << 60));
  dp.at(0).at(0) = 0;

  for (int64_t i = 1; i <= N; i++) {
    for (int64_t j = 0; j <= HP; j++) {
      dp.at(i).at(j) = std::min(dp.at(i).at(j), dp.at(i - 1).at(j));

      if (j - A.at(i) >= 0) {
        dp.at(i).at(j) =
            std::min(dp.at(i).at(j), dp.at(i).at(j - A.at(i)) + B.at(i));
      }
    }
  }

  int64_t answer = 1LL << 60;
  for (int64_t j = H; j <= HP; j++) {
    answer = std::min(answer, dp.at(N).at(j));
  }

  std::cout << answer << std::endl;

  return 0;
}