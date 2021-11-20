#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t W, a, b;
  std::cin >> W >> a >> b;

  if (std::max(a, b) < std::min(a + W, b + W)) {
    std::cout << 0 << std::endl;
  } else if (a < b) {
    std::cout << b - (W + a) << std::endl;
  } else {
    std::cout << a - (W + b) << std::endl;
  }

  return 0;
}
