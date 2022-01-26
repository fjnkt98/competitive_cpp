#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(4 * N - 1);
  for (int64_t i = 0; i < 4 * N - 1; i++) {
    std::cin >> A.at(i);
  }

  int64_t sum = N * (N + 1) / 2;

  std::cout << 4 * sum - std::accumulate(A.begin(), A.end(), 0LL) << std::endl;

  return 0;
}
