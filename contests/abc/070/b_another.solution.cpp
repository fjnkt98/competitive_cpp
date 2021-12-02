#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int32_t A, B, C, D;
  std::cin >> A >> B >> C >> D;

  std::cout << std::max(0, std::min(B, D) - std::max(A, C)) << std::endl;

  return 0;
}
