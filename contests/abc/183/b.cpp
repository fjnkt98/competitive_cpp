#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  int64_t sx, sy, gx, gy;
  std::cin >> sx >> sy >> gx >> gy;

  double x = static_cast<double>(gx * sy + sx * gy) / (gy + sy);

  std::cout << std::fixed << std::setprecision(10) << x << std::endl;

  return 0;
}
