#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t r1, c1, r2, c2;
  std::cin >> r1 >> c1 >> r2 >> c2;

  int64_t answer = 3;

  if (r1 == r2 && c1 == c2) {
    answer = 0;
  } else if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 ||
             std::abs(r1 - r2) + std::abs(c1 - c2) <= 3) {
    answer = 1;
  } else {
    if ((r1 + c1 + r2 + c2) % 2 == 0 ||
        std::abs(r1 - r2) + std::abs(c1 - c2) <= 6 ||
        std::abs((r1 + c1) - (r2 + c2)) <= 3 ||
        std::abs((r1 - c1) - (r2 - c2)) <= 3) {
      answer = 2;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}