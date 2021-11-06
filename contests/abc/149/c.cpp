#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool is_prime(int64_t N) {
  bool prime = true;
  for (int64_t i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      prime = false;
    }
  }
  return prime;
}

int main() {
  int64_t X;
  std::cin >> X;


  for (int64_t i = X; i < 500000; i++) {
    if (is_prime(i)) {
      std::cout << i << std::endl;
      break;
    }
  }
  return 0;
}
