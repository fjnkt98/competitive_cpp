#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t a, b, c;
  std::cin >> a >> b >> c;

  if (a == b) {
    std::cout << c << std::endl;
  } else if (a == c) {
    std::cout << b << std::endl;
  } else if (b == c) {
    std::cout << a << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}
