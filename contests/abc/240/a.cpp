#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t a, b;
  std::cin >> a >> b;

  if (a == 10 || b == 10) {
    if (a == 10) {
      if (b == 1 || b == 9) {
        std::cout << "Yes" << std::endl;
      } else {
        std::cout << "No" << std::endl;
      }
    } else {
      if (a == 1 || a == 9) {
        std::cout << "Yes" << std::endl;
      } else {
        std::cout << "No" << std::endl;
      }
    }
  } else {
    if (std::abs(a - b) == 1) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }

  return 0;
}
