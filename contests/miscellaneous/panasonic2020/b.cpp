#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t H, W;
  std::cin >> H >> W;

  if (H == 1 || W == 1) {
    std::cout << 1 << std::endl;
    return 0;
  }

  if (H % 2 == 0 || W % 2 == 0) {
    std::cout << H * W / 2 << std::endl;
  } else {
    std::cout << H * W / 2 + 1 << std::endl;
  }

  return 0;
}
