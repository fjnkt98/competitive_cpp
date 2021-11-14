#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t gcd(int64_t x, int64_t y) {
 if (x < 0 || x < 0) return -1;

 if (y == 0) return x;
  else return gcd(y, x % y);
}

int main() {
  int64_t A, B, C, D;
  std::cin >> A >> B >> C >> D;

  int64_t answer = B - A + 1;
  answer -= ((B / C) - (A - 1) / C);
  answer -= ((B / D) - (A - 1) / D);

  int64_t lcm = (C * D) / gcd(C, D);
  answer += ((B / lcm) - ((A - 1) / lcm));

  std::cout << answer << std::endl;

  return 0;
}
