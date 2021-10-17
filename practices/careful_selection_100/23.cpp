/*
 * https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> P(N + 1, 0);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> P.at(i);
  }

  std::vector<int64_t> point;
  for (int64_t i = 0; i <= N; i++) {
    for (int64_t j = 0; j <= N; j++) {
      point.push_back(P.at(i) + P.at(j));
    }
  }

  std::sort(point.begin(), point.end());

  int64_t answer = 0;
  for (size_t i = 0; i < point.size(); i++) {
    if (point.at(i) > M) break;
    auto iter = std::upper_bound(point.begin(), point.end(), M - point.at(i));
    int64_t score = point.at(i) + *(iter - 1);
    answer = std::max(answer, score);
  }

  std::cout << answer << std::endl;

  return 0;
}
