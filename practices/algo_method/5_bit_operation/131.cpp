#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::bitset<5> bit("01001");

  std::cout << bit.count() << std::endl;

  return 0;
}