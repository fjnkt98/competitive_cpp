#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int64_t N;
  std::cin >> N;

  int64_t price = std::floor(1.08 * N);

  if (price == 206) {
    std::cout << "so-so" << std::endl;
  } else if (price < 206) {
    std::cout << "Yay!" << std::endl;
  } else {
    std::cout << ":(" << std::endl;
  }

  return 0;
}
