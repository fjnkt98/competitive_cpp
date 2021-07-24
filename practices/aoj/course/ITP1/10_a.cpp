#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
  double x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  double distance = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));

  std::cout << std::fixed << std::setprecision(6) << distance << std::endl;
}
