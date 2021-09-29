/*
 * https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_c
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;

  std::vector<std::vector<int64_t>> A(N, std::vector<int64_t>(M));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < M; j++) {
      std::cin >> A.at(i).at(j);
    }
  }

  int64_t max_point = 0;
  for (int64_t i = 0; i < M; i++) {
    for (int64_t j = i + 1; j < M; j++) {
      int64_t total_point = 0;
      for (int64_t k = 0; k < N; k++) {
        total_point += std::max(A.at(k).at(i), A.at(k).at(j));
      }
      max_point = std::max(max_point, total_point);
    }
  }

  std::cout << max_point << std::endl;

  return 0;
}
