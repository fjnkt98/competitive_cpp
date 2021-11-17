#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> X(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> X.at(i);
  }
  std::sort(X.begin(), X.end());

  if (N >= M) {
    std::cout << 0 << std::endl;
    return 0;
  }

  std::vector<int64_t> diff(M - 1);
  for (int64_t i = 0; i < M - 1; i++) {
    diff.at(i) = X.at(i + 1) - X.at(i);
  }

  std::sort(diff.begin(), diff.end());

  int64_t answer = 0;
  for (int64_t i = 0; i < M - N; i++) {
    answer += diff.at(i);
  }

  std::cout << answer << std::endl;

  return 0;
}
