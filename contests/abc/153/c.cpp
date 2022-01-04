#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> H(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> H.at(i);
  }

  std::sort(H.begin(), H.end(), std::greater<int64_t>{});

  for (int64_t i = 0; i < std::min(K, N); i++) {
    H.at(i) = 0;
  }

  std::cout << std::accumulate(H.begin(), H.end(), 0LL) << std::endl;

  return 0;
}
