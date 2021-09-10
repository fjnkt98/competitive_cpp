#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t iterative_power(int64_t x, int64_t n, int64_t p) {
 if (n == 0) return 1;
 if (n == 1) return x % p;
 if (n % 2 == 1) return (x * iterative_power(x, n - 1, p)) % p;

 int64_t t = iterative_power(x, n / 2, p);
 return (t * t) %p;
}

bool is_prime(int64_t N) {
  bool is_prime = true;
  for (int64_t i = 2; i * i < N; i++) {
    if (N % i == 0) is_prime = false;
  }

  return is_prime;
}

int main() {
  int64_t N;
  std::cin >> N;

  if (is_prime(N)) {
    std::cout << "No" << std::endl;
    return 0;
  }

  bool ok = true;
  for (int64_t i = 1; i < N; i++) {
    if (iterative_power(i, N, N) != i) {
      ok = false;
    }
  }

  if (ok) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
