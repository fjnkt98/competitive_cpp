#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

  std::vector<int64_t> factors(N + 1);
  factors.at(1) = 1;
  for (int64_t i = 2; i <= N; i++) {
    auto primes = prime_factorize(i);

    for (auto p : primes) {
      factors.at(p.first) += p.second;
    }
  }

  /* for (auto f : factors) { */
  /*   std::cout << f << " "; */
  /* } */
  /* std::cout << std::endl; */

  int64_t answer = 1;
  const int64_t mod = 1000000007;

  for (size_t i = 2; i < factors.size(); i++) {
    if (factors.at(i) == 0) continue;
    answer *= (factors.at(i) + 1) % mod;
    answer %= mod;
  }

  std::cout << answer << std::endl;

  return 0;
}
