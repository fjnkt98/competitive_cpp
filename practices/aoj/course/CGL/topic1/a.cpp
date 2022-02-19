#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
  int64_t xp1, yp1, xp2, yp2;
  std::cin >> xp1 >> yp1 >> xp2 >> yp2;
  int64_t Q;
  std::cin >> Q;
  std::vector<int64_t> x(Q);
  std::vector<int64_t> y(Q);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> x.at(i) >> y.at(i);
  }

  for (int64_t i = 0; i < Q; i++) {
    std::vector<int64_t> p = {xp2 - xp1, yp2 - yp1};
    std::vector<int64_t> q = {x.at(i) - xp1, y.at(i) - yp1};

    double ps = std::sqrt(std::pow(p.at(0), 2) + std::pow(p.at(1), 2));
    double qs = std::sqrt(std::pow(q.at(0), 2) + std::pow(q.at(1), 2));

    double inner_product = p.at(0) * q.at(0) + p.at(1) * q.at(1);

    double coefficient = inner_product / std::pow(ps, 2);

    double x = coefficient * p.at(0);
    double y = coefficient * p.at(1);

    std::cout << std::fixed << std::setprecision(10) << xp1 + x << " "
              << yp1 + y << std::endl;
  }

  return 0;
}