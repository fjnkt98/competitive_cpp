#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  int64_t D;
  std::cin >> D;

  std::cout << std::fixed << std::setprecision(10) << static_cast<double>(D) / 100 << std::endl;

  return 0;
}
