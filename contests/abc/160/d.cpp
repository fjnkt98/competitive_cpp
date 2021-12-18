#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, X, Y;
  std::cin >> N >> X >> Y;

  X--;
  Y--;

  std::vector<int64_t> answer(N, 0);
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      answer.at(std::min(j - i, std::abs(X - i) + std::abs(j - Y) + 1))++;
    }
  }

  for (int64_t i = 1; i < N; i++) {
    std::cout << answer.at(i) << std::endl;
  }

  return 0;
}
