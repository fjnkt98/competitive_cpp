#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> x(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> x.at(i);
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    answer += 2 * std::min(x.at(i), std::abs(x.at(i) - K));
  }

  std::cout << answer << std::endl;

  return 0;
}
