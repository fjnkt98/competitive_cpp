#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> problems(2 * N);
  for (int64_t i = 0; i < N; i++) {
    int64_t A, B;
    std::cin >> A >> B;
    problems.at(2 * i) = B;
    problems.at(2 * i + 1) = A - B;
  }

  std::sort(problems.begin(), problems.end(), std::greater<int64_t>{});

  int64_t answer = 0;
  for (int64_t i = 0; i < K; i++) {
    answer += problems.at(i);
  }

  std::cout << answer << std::endl;

  return 0;
}
