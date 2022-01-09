#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int64_t legendre(int64_t N, int64_t p) {
  int64_t result = 0;
  while (N) {
    result += N / p;
    N /= p;
  }

  return result;
}

int main() {
  int64_t N;
  std::cin >> N;

  std::cout << legendre(N, 5) << std::endl;

  return 0;
}