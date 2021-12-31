#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, D;
  std::cin >> N >> D;

  std::cout << N / (2 * D + 1) + static_cast<int64_t>(N % (2 * D + 1) != 0) << std::endl;

  return 0;
}
