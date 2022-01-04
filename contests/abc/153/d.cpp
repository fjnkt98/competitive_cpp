#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t H;
  std::cin >> H;

  int64_t count = 1;
  int64_t answer = 0;

  while (H > 0) {
    answer += count;
    H /= 2;
    count *= 2;
  }

  std::cout << answer << std::endl;

  return 0;
}
