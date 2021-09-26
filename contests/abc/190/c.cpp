#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> A(M);
  std::vector<int64_t> B(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }

  int64_t K;
  std::cin >> K;
  std::vector<int64_t> C(K);
  std::vector<int64_t> D(K);
  for (int64_t i = 0; i < K; i++) {
    std::cin >> C.at(i) >> D.at(i);
  }

  int64_t answer = 0;
  for (int64_t bit = 0; bit < (1 << K); bit++) {
    std::vector<int8_t> dish(N, 0);
    for (int64_t i = 0; i < K ; i++) {
      if (bit & (1 << i)) {
        dish.at(C.at(i) - 1)++;
      } else {
        dish.at(D.at(i) - 1)++;
      }
    }

    int64_t count = 0;
    for (int64_t i = 0; i < M; i++) {
      if (dish.at(A.at(i) - 1) >= 1 && dish.at(B.at(i) - 1) >= 1) {
        count++;
      }
    }

    answer = std::max(answer, count);
  }

  std::cout << answer << std::endl;

  return 0;
}
