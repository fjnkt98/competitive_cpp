#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int64_t sum_of_arithmetic_progression(int64_t a, int64_t n) {
  if (n % 2 == 0) {
    return a * n + (n / 2) * (n - 1);
  } else {
    return a * n + n * ((n - 1) / 2);
  }
}

int main() {
  int64_t N;
  std::cin >> N;

  int64_t M = N;
  while (M % 2 == 0) {
    M /= 2;
  }

  int64_t count = 0;
  int64_t sq = static_cast<int64_t>(std::sqrt(M));
  for (int64_t i = 1; i <= sq; i++) {
    if (M % i == 0) {
      count += 2;
    }
  }

  if (sq * sq == M) {
    count--;
  }

  std::cout << count * 2 << std::endl;

  return 0;
}
