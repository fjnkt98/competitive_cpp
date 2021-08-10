#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t H, W;
  std::cin >> H >> W;

  if (H == 1 || W == 1) {
    std::cout << H * W << std::endl;
  } else {
    std::cout << ((H + 1) / 2) * ((W + 1) / 2) << std::endl;
  }

  return 0;
}
