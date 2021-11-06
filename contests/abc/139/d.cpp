#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  if (N == 1) {
    std::cout << 0 << std::endl;
    return 0;
  } else {
    std::cout << N * (N - 1) / 2 << std::endl;
  }

  return 0;
}
