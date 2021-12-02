#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> L(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> L.at(i);
  }

  std::sort(L.begin(), L.end(), std::greater<int64_t>{});

  int64_t answer = 0;
  for (int64_t i = 0; i < K; i++) {
    answer += L.at(i);
  }

  std::cout << answer << std::endl;

  return 0;
}
