#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::string> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  std::vector<std::string> B(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> B.at(i);
  }

  bool ok = false;
  for (int64_t i = 0; i < N - M + 1; i++) {
    for (int64_t j = 0; j < N - M + 1; j++) {
      bool is_match = true;
      for (int64_t k = 0; k < M; k++) {
        for (int64_t l = 0; l < M; l++) {
          if (A.at(i + k).at(j + l) != B.at(k).at(l)) {
            is_match = false;
          }
        }
      }

      if (is_match) {
        ok = true;
      }
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
