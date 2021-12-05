#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>

double radians(double degree) {
  return 360 * degree / (2 * M_PI);
}

int main() {
  int64_t A, B, X;
  std::cin >> A >> B >> X;

  double a = static_cast<double>(A);
  double b = static_cast<double>(B);
  double x = static_cast<double>(X);

  double answer = 0.0;

  if (x < a * a * b / 2) {
    answer = radians(std::atan2(b, 2 * x / (a * b)));
  } else {
    answer = radians(std::atan2(b - (x / (a * a)), a / 2));
  }

  std::cout << std::fixed << std::setprecision(10) << answer << std::endl;

  return 0;
}
