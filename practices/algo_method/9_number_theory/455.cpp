#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::pair<int64_t, int64_t>> prime_factorize(int64_t N) {
  std::vector<std::pair<int64_t, int64_t>> primes;
  for (int64_t i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      int64_t ex = 0;
      while (N % i == 0) {
        ex++;
        N /= i;
      }
      primes.push_back({i, ex});
    }
  }
  if (N != 1) {
    primes.push_back({N, 1});
  }
  return primes;
}

int main() {
  int64_t A;
  std::cin >> A;

  auto primes = prime_factorize(A);

  int64_t N = 1;
  for (auto p : primes) {
    if (p.second % 2 == 1) {
      N *= p.first;
    }
  }

  std::cout << N << std::endl;

  return 0;
}