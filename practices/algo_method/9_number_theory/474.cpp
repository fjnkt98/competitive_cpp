#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  int64_t A, B, C, D;
  std::cin >> A >> B >> C >> D;

  std::cout << std::gcd(std::abs(A - C), std::abs(B - D)) - 1 << std::endl;

  return 0;
}