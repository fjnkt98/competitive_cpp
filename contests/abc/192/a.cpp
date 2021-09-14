#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t X;
  std::cin >> X;

  std::cout << 100 - (X % 100) << std::endl;

  return 0;
}
