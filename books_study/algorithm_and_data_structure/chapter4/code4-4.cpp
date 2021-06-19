/*
 * Euclidian Algorithm
 */

#include <iostream>

int64_t gcd(int64_t m, int64_t n) {
  // Base case
  if (n == 0) {
    return m;
  }

  return gcd(n, m % n);
}

int main() {
  std::cout << gcd(51, 15) << std::endl;
  std::cout << gcd(15, 51) << std::endl;
}
