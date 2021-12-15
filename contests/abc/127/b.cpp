#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t r, D, x2000;
  std::cin >> r >> D >> x2000;

  int64_t answer = x2000;
  for (int64_t i = 0; i < 10; i ++) {
    answer = r * answer - D;
    std::cout << answer << std::endl;
  }

  return 0;
}
