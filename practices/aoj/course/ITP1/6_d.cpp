#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;

  std::vector<std::vector<int64_t>> A(N, std::vector<int64_t>(M));
  std::vector<int64_t> B(M);
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < M; j++) {
      std::cin >> A.at(i).at(j);
    }
  }

  for (int64_t i = 0; i < M; i++) {
    std::cin >> B.at(i);
  }

  std::vector<int64_t> C(N);
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < M; j++) {
      C.at(i) += A.at(i).at(j) * B.at(j);
    }
  }

  for (int64_t i = 0; i < N; i++) {
    std::cout << C.at(i) << std::endl;
  }

  return 0;
}
