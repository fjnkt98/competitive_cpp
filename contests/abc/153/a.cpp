#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t H, A;
  std::cin >> H >> A;

  std::cout << H / A + static_cast<int64_t>(H % A != 0) << std::endl;

  return 0;
}
