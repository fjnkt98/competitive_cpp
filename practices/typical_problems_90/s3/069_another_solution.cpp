#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t iterative_power(int64_t a, int64_t n, int64_t p) {
  if (n == 0) return 1;
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * iterative_power(a, n - 1, p)) % p;

  int64_t t = iterative_power(a, n / 2, p);
  return (t * t) %p;
}

int main() {
  int64_t N, K;
  std::cin >> N >> K;

  const int64_t mod = 1000000007;

  if (K == 1) {
    if (N == 1) {
      std::cout << 1 << std::endl;
    } else {
      std::cout << 0 << std::endl;
    }
  } else if (N == 1) {
    std::cout << K % mod << std::endl;
  } else if (N == 2) {
    std::cout << (K * (K - 1)) % mod << std::endl;
  } else {
    std::cout << (((K * (K - 1)) % mod) * (iterative_power(K - 2, N - 2, mod) % mod)) % mod << std::endl;
  }

  return 0;
}
