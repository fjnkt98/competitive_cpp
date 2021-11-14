#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  if (N > 2 && M > 2) {
    std::cout << (N - 2) * (M - 2) << std::endl;
  } else {
    if (N == 1 && M == 1) {
      std::cout << 1 << std::endl;
    }

    if (N == 2 || M == 2) {
      std::cout << 0 << std::endl;
    }

    if (N == 1 && M != 1) {
      std::cout << M - 2 << std::endl;
    }

    if (N != 1 && M == 1) {
      std::cout << N - 2 << std::endl;
    }
  }

  return 0;
}
