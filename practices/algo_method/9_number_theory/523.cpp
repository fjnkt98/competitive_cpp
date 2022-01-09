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
  std::vector<int64_t> answer;

  for (int64_t i = 2; i < 1000000; i++) {
    auto dividers = enumerate_dividers(i);

    if (dividers.size() == 6) {
      answer.push_back(i);
    }

    if (answer.size() == 5) {
      break;
    }
  }

  for (size_t i = 0; i < answer.size(); i++) {
    if (i) std::cout << " ";
    std::cout << answer.at(i);
  }
  std::cout << std::endl;

  return 0;
}