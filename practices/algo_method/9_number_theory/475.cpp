#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  std::cout << (A / std::gcd(A, B)) * B << std::endl;

  return 0;
}