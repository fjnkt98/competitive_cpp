#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t minimum_xor = 1LL << 60;
  for (int64_t bit = 0; bit < (1LL << (N - 1)); bit++) {
    int64_t total_xor = 0;
    int64_t total_or = A.at(0);
    for (int64_t i = 1; i < N; i++) {
      if (bit & (1LL << (i - 1))) {
        total_xor ^= total_or;
        total_or = 0;
      }
      total_or |= A.at(i);
    }

    total_xor ^= total_or;

    minimum_xor = std::min(minimum_xor, total_xor);
  }

  std::cout << minimum_xor << std::endl;

  return 0;
}
