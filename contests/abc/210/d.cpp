#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>

int main() {
  int64_t H, W, C;
  std::cin >> H >> W >> C;
  std::vector<std::vector<int64_t>> A(H, std::vector<int64_t>(W));
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      std::cin >> A.at(i).at(j);
    }
  }

  std::pair<int64_t, int64_t> a(0, 0);
  std::pair<int64_t, int64_t> b(0, 1);
  int64_t min_cost = A.at(0).at(0) + A.at(0).at(1) + C;

  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      if (i == 0 && j == 1) {
        continue;
      }

      int64_t cost_a = A.at(i).at(j) + A.at(a.first).at(a.second)
                      + C * (std::abs(i - a.first) + std::abs(j - a.second));
      int64_t cost_b = A.at(i).at(j) + A.at(b.first).at(b.second)
                      + C * (std::abs(i - b.first) + std::abs(j - b.second));

      if (cost_a < min_cost || cost_b < min_cost) {
        if (cost_a < cost_b) {
          b.first = i;
          b.second = j;
          min_cost = cost_a;
        } else {
          a.first = i;
          a.second = j;
          min_cost = cost_b;
        }
      }
    }
  }

  std::cout << min_cost << std::endl;

  return 0;
}
