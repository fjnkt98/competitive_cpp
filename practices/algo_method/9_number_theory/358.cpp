#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool is_prime(int64_t N) {
  if (N == 0 || N == 1) return false;
  if (N == 2) return true;

  for (int64_t i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int64_t N;
  std::cin >> N;

  int64_t answer = 0;
  for (int64_t i = 1; i * i <= N; i++) {
    if (is_prime(i)) {
      answer++;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}