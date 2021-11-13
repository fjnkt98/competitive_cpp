#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t left = 0;
  int64_t right = 1e18 / K;

  while (right - left > 1) {
    int64_t mid = (left + right) / 2;

    int64_t sum = 0;
    for (int64_t i = 0; i < N; i++) {
      sum += std::min(mid, A.at(i));
    }

    if (sum / K >= mid) {
      left = mid;
    } else {
      right = mid;
    }
  }

  std::cout << left << std::endl;

  return 0;
}
