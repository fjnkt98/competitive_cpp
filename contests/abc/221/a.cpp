#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  int64_t answer = 1;
  for (int64_t i = B; i < A; i++) {
    answer *= 32;
  }

  std::cout << answer << std::endl;

  return 0;
}
