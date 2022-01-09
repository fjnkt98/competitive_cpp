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
  int64_t A, B, R, S;
  std::cin >> A >> B >> R >> S;

  int64_t maximum_candidate = std::gcd(A - R, B - S);

  auto dividers = enumerate_dividers(maximum_candidate);
  int64_t answer = 1LL << 60;
  for (int64_t d : dividers) {
    if (A % d == R && B % d == S) {
      answer = std::min(answer, d);
    }
  }

  if (answer == 1LL << 60) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << answer << std::endl;
  }

  return 0;
}