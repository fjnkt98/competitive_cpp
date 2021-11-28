#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N + 2, 0);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> cost(N + 1);
  for (int64_t i = 0; i < N + 1; i++) {
    cost.at(i) = std::abs(A.at(i + 1) - A.at(i));
  }

  int64_t total_cost = std::accumulate(cost.begin(), cost.end(), 0LL);
  for (int64_t i = 1; i <= N; i++) {
    int64_t a = A.at(i - 1);
    int64_t b = A.at(i);
    int64_t c = A.at(i + 1);

    std::cout << total_cost - std::abs(a - b) - std::abs(b - c) + std::abs(a - c) << std::endl;
  }

  return 0;
}
