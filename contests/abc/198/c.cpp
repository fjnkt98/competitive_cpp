#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int64_t R, X, Y;
  std::cin >> R >> X >> Y;

  double target_distance = std::sqrt(X * X + Y * Y);

  int64_t step_count = 0;
  if (std::abs(R - target_distance) < 1e-10) step_count = 1;
  else if (target_distance < 2 * static_cast<double>(R)) step_count = 2;
  else step_count = std::ceil(target_distance / R);

  std::cout << step_count << std::endl;

  return 0;
}
