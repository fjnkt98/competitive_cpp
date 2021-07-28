#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t gcd(int64_t x, int64_t y) {
  int64_t mod = x % y;
  if (mod == 0) {
    return y;
  } else {
    return gcd(y, mod);
  }
}

int main() {
  int64_t x, y;
  std::cin >> x >> y;

  std::cout << gcd(x, y) << std::endl;

  return 0;
}
