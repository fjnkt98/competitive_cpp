#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> A(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t K;
    std::cin >> K;
    for (int64_t j = 0; j < K; j++) {
      int64_t a;
      std::cin >> a;
      A.at(i).push_back(a - 1);
    }
  }

  std::vector<int64_t> favorite(M, 0);
  for (int64_t i = 0; i < N; i++) {
    for (int64_t a : A.at(i)) {
      favorite.at(a)++;
    }
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < M; i++) {
    if (favorite.at(i) == N) {
      answer++;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
