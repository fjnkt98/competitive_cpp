#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  for (int64_t i = 1; i < 50000; i++) {
    int64_t X = i * 108 / 100;
    if (X == N) {
      std::cout << i << std::endl;
      return 0;
    }
  }

  std::cout << ":(" << std::endl;
  return 0;
}
