#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t A, B, C;
  std::cin >> A >> B >> C;

  if (A % 2 == 0 || B % 2 == 0 || C % 2 == 0) {
    std::cout << 0 << std::endl;
  } else {
    int64_t answer = 1LL << 60;

    int64_t diff1 = std::abs(B * C * (A / 2) - B * C * (A - A / 2));
    int64_t diff2 = std::abs(A * C * (B / 2) - A * C * (B - B / 2));
    int64_t diff3 = std::abs(A * B * (C / 2) - A * B * (C - C / 2));

    answer = std::min(diff1, std::min(diff2, diff3));

    std::cout << answer << std::endl;
  }

  return 0;
}