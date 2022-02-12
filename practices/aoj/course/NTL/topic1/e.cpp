#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t extended_gcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  int64_t d = a;
  if (b == 0) {
    x = 1;
    y = 0;
  } else {
    d = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;
  }

  return d;
}

int main() {
  int64_t a, b;
  std::cin >> a >> b;

  int64_t x = 0;
  int64_t y = 0;

  extended_gcd(a, b, x, y);

  std::cout << x << " " << y << std::endl;

  return 0;
}