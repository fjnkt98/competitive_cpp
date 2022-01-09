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
  int64_t N;
  std::cin >> N;

  auto primes = prime_factorize(N);
  std::sort(primes.begin(), primes.end());

  for (size_t i = 0; i < primes.size(); i++) {
    if (i) std::cout << " ";
    for (int64_t j = 0; j < primes.at(i).second; j++) {
      if (j) std::cout << " ";
      std::cout << primes.at(i).first;
    }
  }
  std::cout << std::endl;

  return 0;
}