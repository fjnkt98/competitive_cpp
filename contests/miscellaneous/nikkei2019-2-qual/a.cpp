#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  if (N % 2 == 0) {
    std::cout << N / 2 - 1 << std::endl;
  } else {
    std::cout << N / 2 << std::endl;
  }

  return 0;
}
