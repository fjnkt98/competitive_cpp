#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>

int main() {
  int64_t a, b, c;
  std::cin >> a >> b >> c;

  double S = a * b * std::sin(static_cast<double>(c) * M_PI / 180) / 2;
  double L = a + b + std::sqrt(std::pow(a, 2) + std::pow(b, 2) - 2 * a * b * std::cos(static_cast<double>(c) * M_PI / 180));
  double h = b * std::sin(static_cast<double>(c) * M_PI / 180);

  std::cout << std::fixed << std::setprecision(10) << S << std::endl;
  std::cout << std::fixed << std::setprecision(10) << L << std::endl;
  std::cout << std::fixed << std::setprecision(10) << h << std::endl;

  return 0;
}
