#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N, P;
  std::cin >> N >> P;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t sum = std::accumulate(A.begin(), A.end(), 0LL);

  std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(sum + 1, 0));
  dp.at(0).at(0) = 1;

  for (int64_t i = 1; i <= N; i++) {
    for (int64_t j = 0; j <= sum; j++) {
      dp.at(i).at(j) += dp.at(i - 1).at(j);

      if (j - A.at(i - 1) >= 0) {
        dp.at(i).at(j) += dp.at(i - 1).at(j - A.at(i - 1));
      }
    }
  }

  /* for (auto i : dp) { */
  /*   for (auto j : i) { */
  /*     std::cout << j << " "; */
  /*   } */
  /*   std::cout << std::endl; */
  /* } */

  int64_t answer = 0;
  for (int64_t i = 0; i <= sum; i++) {
    if (dp.at(N).at(i) != 0) {
      if (i % 2 == P) {
        answer += dp.at(N).at(i);
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
