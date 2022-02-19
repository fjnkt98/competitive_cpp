#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int64_t X;
  std::cin >> X;

  if (X < 0) {
    int64_t Y = -X;
    std::cout << -((Y + 9) / 10) << std::endl;
  } else {
    std::cout << (X - X % 10) / 10 << std::endl;
  }

  return 0;
}
