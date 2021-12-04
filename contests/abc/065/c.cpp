#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;

  constexpr int64_t mod = 1000000007;

  int64_t answer = 0;
  if (std::abs(N - M) > 1) {
    answer = 0;
  } else {
    int64_t x = 1;
    for (int64_t i = N; i > 0; i--) {
      x *= i;
      x %= mod;
    }
    int64_t y = 1;
    for (int64_t i = M; i > 0; i--) {
      y *= i;
      y %= mod;
    }

    answer = x * y % mod;

    if (N == M) {
      answer *= 2;
      answer %= mod;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
