#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t X;
  std::cin >> X;

  std::cout << 1000 * (X / 500) + 5 * ((X % 500) / 5) << std::endl;

  return 0;
}
