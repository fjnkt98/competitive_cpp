#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int64_t> eratosthenes_sieve(int64_t N) {
  std::vector<int64_t> primes;
  std::vector<bool> is_prime(N + 1, true);
  is_prime.at(0) = false;
  is_prime.at(1) = false;

  for (int64_t i = 2; i <= N; i++) {
    if (is_prime.at(i)) {
      primes.push_back(i);
      for (int64_t j = 2 * i; j <= N; j += i) is_prime.at(j) = false;
    }
  }

  return primes;
}

int main() {
  int64_t N;
  std::cin >> N;

  auto primes = eratosthenes_sieve(N);

  for (size_t i = 0; i < primes.size(); i++) {
    if (i) std::cout << " ";
    std::cout << primes.at(i);
  }
  std::cout << std::endl;

  return 0;
}
