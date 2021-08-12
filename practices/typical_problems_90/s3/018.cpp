#include <ios>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
  int64_t T, L, X, Y;
  std::cin >> T >> L >> X >> Y;
  int64_t Q;
  std::cin >> Q;
  std::vector<int64_t> E(Q);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> E.at(i);
  }

  for (int64_t i = 0; i < Q; i++) {
    double wheel_angle_radians = 2 * M_PI * E.at(i) / T;
    double y = -L * std::sin(wheel_angle_radians) / 2;
    double z = L * (1 - std::cos(wheel_angle_radians)) / 2;

    double horizontal_distance = std::sqrt(std::pow(X, 2) + std::pow(Y - y, 2));

    double angle_of_dip = std::atan2(z, horizontal_distance);

    std::cout << std::fixed << std::setprecision(15) << angle_of_dip * 180 / M_PI << std::endl;
  }

  return 0;
}
