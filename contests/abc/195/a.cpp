#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t M, H;
  std::cin >> M >> H;

  if (H % M == 0) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
