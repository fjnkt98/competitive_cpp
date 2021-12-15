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
  int64_t A, B;
  std::cin >> A >> B;

  std::cout << A * B / gcd(A, B) << std::endl;


  return 0;
}
