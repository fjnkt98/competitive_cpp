#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
  int64_t N, M;
  std::cin >> N >> M;

  auto dividers = enumerate_dividers(M);

  int64_t answer = 0;
  for (auto d : dividers) {
    if (d <= (M / N)) {
      answer = std::max(answer, d);
    }
  }

  std::cout << answer << std::endl;

  return 0;
}