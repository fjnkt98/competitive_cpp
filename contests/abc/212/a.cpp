#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  if (A > 0 && B == 0) {
    std::cout << "Gold" << std::endl;
  } else if (A == 0 && B > 0) {
    std::cout << "Silver" << std::endl;
  } else {
    std::cout << "Alloy" << std::endl;
  }

  return 0;
}
