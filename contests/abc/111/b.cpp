#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  for (int64_t i = 0; i <= 9; i++) {
    if (N <= i * 111) {
      std::cout << i * 111 << std::endl;
      break;
    }
  }

  return 0;
}
