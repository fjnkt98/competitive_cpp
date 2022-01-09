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

  if (N == 1) {
    std::cout << 1 << std::endl;
    return 0;
  }

  auto primes = prime_factorize(N);
  bool flag = false;
  for (auto p : primes) {
    if (p.second >= 2) {
      flag = true;
    }
  }

  if (flag) {
    std::cout << 0 << std::endl;
    return 0;
  }

  flag = true;
  for (auto p : primes) {
    if (p.second != 1) {
      flag = false;
    }
  }

  if (flag) {
    if (primes.size() % 2 == 0) {
      std::cout << 1 << std::endl;
    } else {
      std::cout << -1 << std::endl;
    }
  }

  return 0;
}