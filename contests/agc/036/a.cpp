#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t S;
  std::cin >> S;

  int64_t x1 = 0;
  int64_t x2 = 1e9;
  int64_t y1 = 0;
  int64_t y2 = 1;

  int64_t dv = 1000000000;

  int64_t x3 = (dv - S % dv) % dv;
  int64_t y3 = (S + x3) / dv;

  std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " "
            << y3 << std::endl;

  return 0;
}