#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t L, R;
  std::cin >> L >> R;

  int64_t answer = 1LL << 60;
  if (R - L > 2019) {
    answer = 0;
  } else {
    for (int64_t i = L; i <= R; i++) {
      for (int64_t j = i + 1; j <= R; j++) {
        answer = std::min(answer, (i * j) % 2019);
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
