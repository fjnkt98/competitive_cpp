#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::vector<int64_t> enumerate_dividers(int64_t N) {
  std::vector<int64_t> dividers;

  for (int64_t i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      dividers.push_back(i);

      if (N / i != i) {
        dividers.push_back(N / i);
      }
    }
  }

  std::sort(dividers.begin(), dividers.end());
  return dividers;
}

int main() {
  int64_t G, M;
  std::cin >> G >> M;

  if (M % G != 0) {
    std::cout << -1 << std::endl;
    return 0;
  }

  auto dividers = enumerate_dividers(M / G);
  int64_t answer = 1LL << 60;
  for (auto d : dividers) {
    if (std::gcd(d, (M / G) / d) == 1) {
      answer = std::min(answer, G * d + G * (M / G) / d);
    }
  }

  std::cout << answer << std::endl;

  return 0;
}