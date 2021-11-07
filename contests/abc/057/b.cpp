#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }
  std::vector<int64_t> C(M);
  std::vector<int64_t> D(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> C.at(i) >> D.at(i);
  }

  std::vector<int64_t> checkpoints(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t minimum_distance = 1LL << 60;
    for (int64_t j = M - 1; j >= 0; j--) {
      int64_t distance = std::abs(A.at(i) - C.at(j)) + std::abs(B.at(i) - D.at(j));
      if (minimum_distance >= distance) {
        minimum_distance = distance;
        checkpoints.at(i) = j + 1;
      }
    }
  }

  for (int64_t c : checkpoints) {
    std::cout << c << std::endl;
  }

  return 0;
}
