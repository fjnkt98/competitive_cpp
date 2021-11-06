#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M, X;
  std::cin >> N >> M >> X;
  std::vector<int64_t> A(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> grid(N + 1);
  for (int64_t i = 0; i < M; i++) {
    grid.at(A.at(i)) = 1;
  }

  int64_t cost_to_N = 0;
  int64_t cost_to_0 = 0;
  for (int64_t i = X; i <= N; i++) {
    cost_to_N += grid.at(i);
  }
  for (int64_t i = X; i >= 0; i--) {
    cost_to_0 += grid.at(i);
  }

  std::cout << std::min(cost_to_0, cost_to_N) << std::endl;

  return 0;
}
