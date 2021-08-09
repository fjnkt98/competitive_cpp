#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, C;
  std::cin >> A >> B >> C;

  if (C % 2 == 0) {
    if (std::abs(A) == std::abs(B)) {
      std::cout << "=" << std::endl;
    } else if (std::abs(A) < std::abs(B)) {
      std::cout << "<" << std::endl;
    } else {
      std::cout << ">" << std::endl;
    }
  } else {
    if (A == B) {
      std::cout << "=" << std::endl;
    } else if (A < B) {
      std::cout << "<" << std::endl;
    } else {
      std::cout << ">" << std::endl;
    }
  }

  return 0;
}
