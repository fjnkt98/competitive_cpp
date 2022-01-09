#include <algorithm>
#include <iostream>
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
  std::vector<int64_t> answer(10);
  for (int64_t i = 1; i < 10; i++) {
    for (int64_t j = 0; j < 10000; j++) {
      auto dividers = enumerate_dividers(j);

      if (dividers.size() == i) {
        answer.at(i) = j;
        break;
      }
    }
  }

  for (auto a : answer) {
    std::cout << a << std::endl;
  }

  return 0;
}