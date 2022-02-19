#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int64_t outer_product(std::vector<int64_t> a, std::vector<int64_t> b) {
  return a.at(0) * b.at(1) - a.at(1) * b.at(0);
}

int64_t inner_product(std::vector<int64_t> a, std::vector<int64_t> b) {
  return a.at(0) * b.at(0) + a.at(1) * b.at(1);
}

double norm(std::vector<int64_t> x) {
  return std::sqrt(std::pow(x.at(0), 2) + std::pow(x.at(1), 2));
}

int64_t ccw(std::vector<int64_t> a, std::vector<int64_t> b) {
  int64_t op = outer_product(a, b);

  if (op > 0) {
    return 1;
  } else if (op < 0) {
    return -1;
  } else {
    if (inner_product(a, b) < 0) {
      return 2;
    } else {
      if (norm(a) < norm(b)) {
        return -2;
      } else {
        return 0;
      }
    }
  }
}

int main() {
  int64_t q;
  std::cin >> q;
  std::vector<int64_t> result;
  for (int64_t i = 0; i < q; i++) {
    int64_t x0, y0, x1, y1, x2, y2, x3, y3;
    std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  }

  for (auto r : result) {
    std::cout << r << std::endl;
  }

  return 0;
}