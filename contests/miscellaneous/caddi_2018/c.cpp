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
  int64_t N, P;
  std::cin >> N >> P;

  auto primes = prime_factorize(P);
  /* primes.push_back(std::make_pair(P, 1)); */

  std::vector<int64_t> candidate;
  for (auto& p : primes) {
    while (p.second >= N) {
      candidate.push_back(p.first);
      p.second -= N;
    }
  }

  int64_t answer = 1;
  for (auto c : candidate) {
    answer *= c;
  }

  std::cout << answer << std::endl;

  return 0;
}
