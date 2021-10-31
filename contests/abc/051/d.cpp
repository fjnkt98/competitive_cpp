#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> A(M);
  std::vector<int64_t> B(M);
  std::vector<int64_t> C(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> A.at(i) >> B.at(i) >> C.at(i);
    A.at(i)--;
    B.at(i)--;
  }

  std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(N, 1LL << 60));
  for (int64_t i = 0; i < M; i++) {
    dp.at(A.at(i)).at(B.at(i)) = C.at(i);
    dp.at(B.at(i)).at(A.at(i)) = C.at(i);
  }
  for (int64_t i = 0; i < N; i++) {
    dp.at(i).at(i) = 0;
  }

  for (int64_t k = 0; k < N; k++) {
    for (int64_t i = 0; i < N; i++) {
      for (int64_t j = 0; j < N; j++) {
        dp.at(i).at(j) = std::min(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k).at(j));
      }
    }
  }

  int64_t answer = M;
  for (int64_t i = 0; i < M; i++) {
    bool belong_shortest_path = false;
    for (int64_t j = 0; j < N; j++) {
      if (dp.at(j).at(A.at(i)) + C.at(i) == dp.at(j).at(B.at(i))) {
        belong_shortest_path = true;
      }
    }

    if (belong_shortest_path) {
      answer--;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
