#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  if (A >= 13) {
    std::cout << B << std::endl;
  } else if (A >= 6) {
    std::cout << B / 2 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}
