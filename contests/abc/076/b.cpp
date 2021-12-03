#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;

  int64_t answer = 1LL << 60;
  for (int64_t bit = 0; bit < (1 << N); bit++) {
    int64_t value = 1;

    for (int64_t i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        value *= 2;
      } else {
        value += K;
      }
    }

    answer = std::min(answer, value);
  }

  std::cout << answer << std::endl;

  return 0;
}
