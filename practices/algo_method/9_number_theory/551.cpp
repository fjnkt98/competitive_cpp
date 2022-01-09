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
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::sort(A.begin(), A.end());

  int64_t gcd = A.at(1) - A.at(0);
  for (int64_t i = 2; i < N; i++) {
    gcd = std::gcd(gcd, A.at(i) - A.at(0));
  }

  auto dividers = enumerate_dividers(gcd);
  std::cout << dividers.size() << std::endl;

  return 0;
}