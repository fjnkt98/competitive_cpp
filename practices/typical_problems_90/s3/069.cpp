#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int64_t mod = 1000000007;

int64_t iterative_pow(int64_t x, int64_t n) {
  if (n <= 0) return 1;
  int64_t result = 1;
  while (n != 0) {
    if (n % 2 == 1) {
      result = (result * x) % mod;
    }
    x = (x * x) % mod;
    n /= 2;
  }
  return result;
}

int main() {
  int64_t N, K;
  std::cin >> N >> K;

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
    std::cout << (((K * (K - 1)) % mod) * (iterative_pow(K - 2, N - 2) % mod)) % mod << std::endl;
  }

  return 0;
}
