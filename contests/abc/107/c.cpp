#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> X(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> X.at(i);
  }

  int64_t answer = 1LL << 60;
  for (int64_t i = 0; i < N - K + 1; i++) {
    int64_t left = X.at(i);
    int64_t right = X.at(i + K - 1);
    answer = std::min(answer, std::abs(left) + std::abs(right - left));
    answer = std::min(answer, std::abs(right) + std::abs(right - left));
  }

  std::cout << answer << std::endl;

  return 0;
}
