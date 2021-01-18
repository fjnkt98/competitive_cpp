#include <bits/stdint-intn.h>
#include <iostream>
#include <vector>

std::vector<int64_t>
eratosthenes_sieve(const int64_t N) {
  std::vector<bool> is_prime(N - 1);
  // Initialize array elements
  for (auto idx : is_prime) {
    idx = true;
  }

  std::vector<int64_t> primes;

  for (int64_t i = 2; i <= N; i++) {
    if (is_prime.at(i - 2)) {
      for (int64_t j = i * 2; j <= N; j += i) {
        is_prime.at(j - 2) = false;
      }
      primes.push_back(i);
    }
  }

  return primes;
}

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> primes = eratosthenes_sieve(N);

  for (auto p : primes) {
    std::cout << p << std::endl;
  }

  return 0;
}
