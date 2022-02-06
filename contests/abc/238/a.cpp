#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;

  if (N == 1) {
    std::cout << "Yes" << std::endl;
    return 0;
  }

  if (N <= 4) {
    std::cout << "No" << std::endl;
    return 0;
  }

  std::cout << "Yes" << std::endl;

  return 0;
}
