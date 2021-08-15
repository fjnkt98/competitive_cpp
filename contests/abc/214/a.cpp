#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  
  if (N < 126) {
    std::cout << 4 << std::endl;
  } else if (N < 212) {
    std::cout << 6 << std::endl;
  } else {
    std::cout << 8 << std::endl;
  }

  return 0;
}
