#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t x;
  std::cin >> x;

  std::bitset<32> b(x);

  std::cout << b << std::endl;
  std::cout << ~b << std::endl;
  std::cout << (b << 1) << std::endl;
  std::cout << (b >> 1) << std::endl;

  return 0;
}