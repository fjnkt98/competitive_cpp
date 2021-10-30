#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> B(N, std::vector<int64_t>(M, -1));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < M; j++) {
      std::cin >> B.at(i).at(j);
    }
  }

  std::vector<std::vector<int64_t>> C(N, std::vector<int64_t>(M, -1));
  C.at(0).at(0) = B.at(0).at(0);
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < M; j++) {
      C.at(i).at(j) = C.at(0).at(0) + 7 * i + j;
    }
  }

  bool ok = true;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < M - 1; j++) {
      if (B.at(i).at(j) % 7 == 0) {
        ok = false;
      }
    }
  }

  if (ok && B == C) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
