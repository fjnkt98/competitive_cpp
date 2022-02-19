#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>

int main() {
  int64_t H;
  std::cin >> H;

  std::cout << std::fixed << std::setprecision(10);
  std::cout << std::sqrt(H * (12800000 + H)) << std::endl;

  return 0;
}
