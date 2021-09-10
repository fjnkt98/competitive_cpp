#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <chrono>

std::vector<int64_t> eratosthenes_sieve(int64_t N) {
  std::vector<int64_t> primes;
  std::vector<bool> is_prime(N + 1, true);
  is_prime.at(0) = false;
  is_prime.at(1) = false;

  for (int64_t i = 2; i <= N; i++) {
    if (is_prime.at(i)) {
      primes.push_back(i);
      for (int64_t j = 2 * i; j <= N; j += i) {
        is_prime.at(j) = false;
      }
    }
  }

  return primes;
}

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  int64_t b_sqrt = static_cast<int64_t>(std::sqrt(static_cast<double>(B)) + 1);

  std::vector<bool> is_prime(B - A, true);
  std::vector<bool> is_prime_small(b_sqrt, true);

  for (int64_t i = 2; i * i <= B; i++) {
    if (is_prime_small.at(i)) {
      for (int64_t j = 2 * i; j * j <= B; j += i) {
        is_prime_small.at(j) = false;
      }
      for (int64_t j = std::max(static_cast<int64_t>(2), (A + i - 1) / i) * i; j <= B; j += i) {
        if (j - A >= 0) is_prime.at(j - A) = false;
      }
    }
  }

  int64_t count = 0;
  for (size_t i = 0; i < is_prime.size(); i++) {
    if (is_prime.at(i)) count++;
  }

  std::cout << count << std::endl;

  return 0;
}
