#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M, C;
  std::cin >> N >> M >> C;
  std::vector<int64_t> B(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> B.at(i);
  }
  std::vector<std::vector<int64_t>> A(N, std::vector<int64_t>(M));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < M; j++) {
      std::cin >> A.at(i).at(j);
    }
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    int64_t sum = C;
    for (int64_t j = 0; j < M; j++) {
      sum += A.at(i).at(j) * B.at(j);
    }

    if (sum > 0) {
      count++;
    }
  }
  std::cout << count << std::endl;

  return 0;
}
