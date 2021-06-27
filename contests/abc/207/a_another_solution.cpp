#include <iostream>
#include <algorithm>

int main() {
  int64_t A, B, C;
  std::cin >> A >> B >> C;

  std::cout << (A + B + C) - std::min(std::min(A, B), C) << std::endl;

  return 0;
}
