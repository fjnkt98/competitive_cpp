#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t fibonacci(int64_t i) {
  if (i == 0 || i == 1) return 1;
  return fibonacci(i - 1) + fibonacci(i - 2);
}

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> fibonacci(N + 1);
  fibonacci.at(0) = fibonacci.at(1) = 1;
  for (int64_t i = 2; i <= N; i++) {
    fibonacci.at(i) = fibonacci.at(i - 1) + fibonacci.at(i - 2);
  }

  std::cout << fibonacci.at(N) << std::endl;

  return 0;
}
