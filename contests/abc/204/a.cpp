#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t x, y;
  std::cin >> x >> y;

  if (x == y) {
    std::cout << x << std::endl;
  } else {
    std::cout << 3 - x - y << std::endl;
  }

  return 0;
}
