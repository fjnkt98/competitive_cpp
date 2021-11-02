#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> X(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> X.at(i);
  }

  int64_t max_x = *std::max_element(X.begin(), X.end());
  int64_t answer = 1LL << 60;
  for (int64_t p = 0; p <= max_x; p++) {
    int64_t sum = 0;
    for (int64_t i = 0; i < N; i++) {
      sum += (X.at(i) - p) * (X.at(i) - p);
    }
    answer = std::min(answer, sum);
  }

  std::cout << answer << std::endl;

  return 0;
}
