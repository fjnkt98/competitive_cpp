#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  if (A > 8 || B > 8) {
    std::cout << ":(" << std::endl;
  } else {
    std::cout << "Yay!" << std::endl;
  }

  return 0;
}
