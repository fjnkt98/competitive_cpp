#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> t(N + 1);
  std::vector<int64_t> x(N + 1);
  std::vector<int64_t> y(N + 1);
  t.at(0) = 0;
  x.at(0) = 0;
  y.at(0) = 0;
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> t.at(i) >> x.at(i) >> y.at(i);
  }

  bool can = true;
  for (int64_t i = 1; i <= N; i++) {
    int64_t dt = t.at(i) - t.at(i - 1);
    int64_t distance = std::abs(x.at(i) - x.at(i - 1)) + std::abs(y.at(i) - y.at(i - 1));

    if (dt < distance) {
      can = false;
    }
    if (distance % 2 != dt % 2) {
      can = false;
    }
  }

  if (can) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
