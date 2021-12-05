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
  int64_t N;
  std::cin >> N;

  auto dividers = enumerate_dividers(N);

  int64_t answer = 1LL << 60;
  for (size_t i = 0; i < dividers.size(); i++) {
    answer = std::min(answer, std::abs(dividers.at(i) - 1) + std::abs(N / dividers.at(i) - 1));
  }

  std::cout << answer << std::endl;

  return 0;
}
