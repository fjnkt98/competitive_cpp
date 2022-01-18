#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t a, b;
  std::cin >> a >> b;

  std::bitset<32> x(a);
  std::bitset<32> y(b);

  std::cout << (x & y) << std::endl;
  std::cout << (x | y) << std::endl;
  std::cout << (x ^ y) << std::endl;

  return 0;
}