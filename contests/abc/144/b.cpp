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

  bool ok = false;
  for (int64_t d : dividers) {
    if (d < 10 && (N / d) < 10) {
      ok = true;
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;

  }

  return 0;
}
