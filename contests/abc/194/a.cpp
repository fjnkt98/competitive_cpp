#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  if (A + B >= 15 && B >= 8) {
    std::cout << 1 << std::endl;
  } else if (A + B >= 10 && B >= 3) {
    std::cout << 2 << std::endl;
  } else if (A + B >= 3) {
    std::cout << 3 << std::endl;
  } else {
    std::cout << 4 << std::endl;
  }

  return 0;
}
