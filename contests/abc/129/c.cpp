#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> A(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> A.at(i);
  }

  std::set<int64_t> broken_step;
  for (int64_t i = 0; i < M; i++) {
    broken_step.insert(A.at(i));
  }

  constexpr int64_t mod = 1000000007;

  std::vector<int64_t> dp(N + 1, 0);
  dp.at(0) = 1;

  for (int64_t i = 0; i <= N; i++) {
    if (i + 1 <= N && broken_step.find(i + 1) == broken_step.end()) {
      dp.at(i + 1) += dp.at(i) % mod;
      dp.at(i + 1) %= mod;
    }

    if (i + 2 <= N && broken_step.find(i + 2) == broken_step.end()) {
      dp.at(i + 2) += dp.at(i) % mod;
      dp.at(i + 2) %= mod;
    }
  }

  std::cout << dp.at(N) << std::endl;


  return 0;
}
