#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;

  if (2 * N >= M) {
    std::cout << M / 2 << std::endl;
  } else {
    std::cout << N + (M - 2 * N) / 4 << std::endl;
  }

  return 0;
}
