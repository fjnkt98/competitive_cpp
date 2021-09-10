#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int64_t gcd(int64_t x, int64_t y) {
 if (x < 0 || x < 0) return -1;

 if (y == 0) return x;
  else return gcd(y, x % y);
}

int main() {
  int64_t px1, py1, px2, py2;
  std::cin >> px1 >> py1 >> px2 >> py2;

  if (px1 == px2 && py1 == py2) {
    std::cout << 0 << std::endl;
  } else {
    std::cout << gcd(std::abs(px1 - px2), std::abs(py1 - py2)) - 1 << std::endl;
  }

  return 0;
}
