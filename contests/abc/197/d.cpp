#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
  int64_t N;
  std::cin >> N;
  double x_0, y_0, x_halfN, y_halfN;
  std::cin >> x_0 >> y_0 >> x_halfN >> y_halfN;

  double x_center = (x_0 + x_halfN) / 2;
  double y_center = (y_0 + y_halfN) / 2;

  double angle = 2 * M_PI / N;
  double x = (x_0 - x_center) * std::cos(angle) - (y_0 - y_center) * std::sin(angle) + x_center;
  double y = (x_0 - x_center) * std::sin(angle) + (y_0 - y_center) * std::cos(angle) + y_center;

  std::cout << std::fixed << std::setprecision(12) << x << " " << y << std::endl;

  return 0;
}
