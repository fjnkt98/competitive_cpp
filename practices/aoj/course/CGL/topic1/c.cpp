#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
  int64_t xp0, yp0, xp1, yp1;
  std::cin >> xp0 >> yp0 >> xp1 >> yp1;
  int64_t q;
  std::cin >> q;
  std::vector<int64_t> x(q);
  std::vector<int64_t> y(q);
  for (int64_t i = 0; i < q; i++) {
    std::cin >> x.at(i) >> y.at(i);
  }

  for (int64_t i = 0; i < q; i++) {
    std::vector<int64_t> p1 = {xp1 - xp0, yp1 - yp0};
    std::vector<int64_t> p2 = {x.at(i) - xp0, y.at(i) - yp0};

    int64_t outer_product = p1.at(0) * p2.at(1) - p2.at(0) * p1.at(1);

    if (outer_product > 0) {
      std::cout << "COUNTER_CLOCKWISE" << std::endl;
    } else if (outer_product < 0) {
      std::cout << "CLOCKWISE" << std::endl;
    } else {
      double p1_scalar =
          std::sqrt(std::pow(p1.at(0), 2) + std::pow(p1.at(1), 2));
      double p2_scalar =
          std::sqrt(std::pow(p2.at(0), 2) + std::pow(p2.at(1), 2));

      int64_t inner_product = p1.at(0) * p2.at(0) + p1.at(1) * p2.at(1);
      if (inner_product < 0) {
        std::cout << "ONLINE_BACK" << std::endl;
      } else {
        if (p1_scalar < p2_scalar) {
          std::cout << "ONLINE_FRONT" << std::endl;
        } else {
          std::cout << "ON_SEGMENT" << std::endl;
        }
      }
    }
  }

  return 0;
}