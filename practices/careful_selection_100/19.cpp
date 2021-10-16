/*
 * https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t L, N, M;
  std::cin >> L >> N >> M;
  std::vector<int64_t> D(N, 0);
  for (int64_t i = 1; i < N; i++) {
    std::cin >> D.at(i);
  }
  std::vector<int64_t> K(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> K.at(i);
  }

  D.push_back(L);
  std::sort(D.begin(), D.end());

  int64_t answer = 0;
  for (int64_t k : K) {
    auto iter = std::lower_bound(D.begin(), D.end(), k);
    answer += std::min(std::abs(k - *iter), std::abs(k - *(iter - 1)));
  }

  std::cout << answer << std::endl;

  return 0;
}
