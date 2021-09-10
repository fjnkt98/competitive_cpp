#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  bool is_prime = true;
  if (N == 1) {
    std::cout << "No" << std::endl;
    return 0;
  }
  for (int64_t i = 2; i * i <= N; i++) {
    if (N % i == 0) is_prime = false;
  }

  if (is_prime) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
