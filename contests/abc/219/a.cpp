#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t X;
  std::cin >> X;

  if (X >= 90) {
    std::cout << "expert" << std::endl;
  } else if (X >= 70) {
    std::cout << 90 - X << std::endl;
  } else if (X >= 40) {
    std::cout << 70 - X << std::endl;
  } else {
    std::cout << 40 - X << std::endl;
  }

  return 0;
}
