#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  std::bitset<8> bA(A);
  std::bitset<8> bB(B);
  for (int64_t i = 0; i < 256; i++) {
    std::bitset<8> bi(i);
    if ((bA ^ bi) == B) {
      std::cout << i << std::endl;
      break;
    }
  }

  return 0;
}
