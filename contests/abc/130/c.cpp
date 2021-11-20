#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  int64_t W, H, x, y;
  std::cin >> W >> H >> x >> y;

  double area = static_cast<double>(W * H) / 2;

  int64_t answer = (W % 2 == 0 && H % 2 == 0 && x == W / 2 && y == H / 2) ? 1 : 0;

  std::cout << std::fixed << std::setprecision(10) << area << " " << answer <<  std::endl;

  return 0;
}
