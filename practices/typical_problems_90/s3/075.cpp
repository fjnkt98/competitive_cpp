#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int64_t> prime_factorization(int64_t N) {
  std::vector<int64_t> primes;

  for (int64_t i = 2; i * i <= N; i++) {
    if (N % i != 0) continue;
    while (N % i == 0) {
      primes.push_back(i);
      N /= i;
    }
  }

  if (N != 1) {
    primes.push_back(N);
  }

  return primes;
}

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> primes = prime_factorization(N);
  int64_t number_of_primes = static_cast<int64_t>(primes.size());

  int64_t answer = 0;
  for (int64_t i = 0; i <= 20; i++) {
    if ((1 << i) >= number_of_primes) {
      answer = i;
      break;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
