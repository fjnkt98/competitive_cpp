/*
 * https://atcoder.jp/contests/arc054/tasks/arc054_b
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

double f(double x, double P) {
  return 1 - P * std::pow(2, -x / 1.5) * std::log(2) / 1.5;
}

int main() {
  double P;
  std::cin >> P;

  double left = 0.0;
  double right = P;
  while (right - left > 0.0000001) {
    double mid = (right + left) /2;

    if (f(mid, P) > 0) {
      right = mid;
    } else {
      left = mid;
    }
  }

  std::cout << std::fixed << std::setprecision(10) << left + P / std::pow(2, left / 1.5) << std::endl;

  return 0;
}
