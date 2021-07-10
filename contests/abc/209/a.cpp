#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B;

  std::cin >> A >> B;

  if (A <= B) {
    std::cout << B - A + 1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}
