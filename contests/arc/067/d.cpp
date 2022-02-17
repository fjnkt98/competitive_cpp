#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, A, B;
  std::cin >> N >> A >> B;
  std::vector<int64_t> X(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> X.at(i);
  }

  std::vector<int64_t> diff(N);
  for (int64_t i = 1; i < N; i++) {
    diff.at(i) = X.at(i) - X.at(i - 1);
  }

  int64_t answer = 0;
  for (int64_t i = 1; i < N; i++) {
    answer += std::min(A * diff.at(i), B);
  }

  std::cout << answer << std::endl;

  return 0;
}