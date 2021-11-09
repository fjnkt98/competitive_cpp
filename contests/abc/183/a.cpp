#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t x;
  std::cin >> x;

  if (x >= 0) {
    std::cout << x << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}
