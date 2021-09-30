/*
 * https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> X(N);
  std::vector<int64_t> Y(N);
  std::vector<std::vector<int8_t>> p(5100, std::vector<int8_t>(5100, 0));
  for (int64_t i = 0; i < N; i++) {
    int64_t x, y;
    std::cin >> x >> y;
    X.at(i) = x;
    Y.at(i) = y;
    p.at(x).at(y) = 1;
  }

  int64_t max_area = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      int64_t diffX = std::abs(X.at(i) - X.at(j));
      int64_t diffY = std::abs(Y.at(i) - Y.at(j));

      int64_t c1_x = X.at(i) + diffY;
      int64_t c1_y = Y.at(i) + diffX;
      int64_t c2_x = X.at(j) + diffY;
      int64_t c2_y = Y.at(j) + diffX;
      if (c1_x >= 0 && c1_x <= 5000 && c1_y >= 0  && c1_y <= 5000
          && c2_x >= 0 && c2_x <= 5000 && c2_y >= 0 && c2_y <= 5000)
      {
        if (p.at(c1_x).at(c1_y) == 1 && p.at(c2_x).at(c2_y) == 1) {
          max_area = std::max(max_area, diffX * diffX + diffY * diffY);
        }
      }

      c1_x = X.at(i) - diffY;
      c1_y = Y.at(i) - diffX;
      c2_x = X.at(j) - diffY;
      c2_y = Y.at(j) - diffX;
      if (c1_x >= 0 && c1_x <= 5000 && c1_y >= 0  && c1_y <= 5000
          && c2_x >= 0 && c2_x <= 5000 && c2_y >= 0 && c2_y <= 5000)
      {
        if (p.at(c1_x).at(c1_y) == 1 && p.at(c2_x).at(c2_y) == 1) {
          max_area = std::max(max_area, diffX * diffX + diffY * diffY);
        }
      }
    }
  }

  std::cout << max_area << std::endl;

  return 0;
}
