#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> A_squared(N);
  for (int64_t i = 0; i < N; i++) {
    A_squared.at(i) = A.at(i) * A.at(i);
  }

  int64_t A_sum = std::accumulate(A.begin(), A.end(), 0LL);
  int64_t A_squared_sum = std::accumulate(A_squared.begin(), A_squared.end(), 0LL);

  int64_t answer = N * A_squared_sum - A_sum * A_sum;
  std::cout << answer << std::endl;

  return 0;
}
