/*
 * https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }

  std::vector<int64_t> C(2 * N);
  for (int64_t i = 0; i < N; i++) {
    C.at(i) = A.at(i);
  }
  for (int64_t i = 0; i < N; i++) {
    C.at(N + i) = B.at(i);
  }

  int64_t answer = 1LL << 60;
  for (int64_t i = 0; i < 2 * N; i++) {
    for (int64_t j = 0; j < 2 * N; j++) {
      int64_t total_distance = 0;
      for (int64_t k = 0; k < N; k++) {
        total_distance += std::abs(C.at(i) - A.at(k)) + std::abs(A.at(k) - B.at(k)) + std::abs(C.at(j) - B.at(k));
      }
      answer = std::min(answer, total_distance);
    }
  }

  std::cout << answer << std::endl;
}
