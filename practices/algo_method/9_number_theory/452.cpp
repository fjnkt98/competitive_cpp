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

  std::vector<int64_t> count(N + 1);

  for (int64_t i = 2; i <= N; i++) {
    auto primes = prime_factorize(i);

    for (auto p : primes) {
      count.at(p.first) += p.second;
    }
  }

  int64_t answer = 1;
  for (int64_t i = 0; i <= N; i++) {
    if (count.at(i) != 0) {
      answer *= (count.at(i) + 1);
    }
  }

  std::cout << answer << std::endl;

  return 0;
}