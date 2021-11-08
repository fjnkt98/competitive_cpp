#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

int64_t gcd(int64_t x, int64_t y) {
 if (x < 0 || x < 0) return -1;

 if (y == 0) return x;
  else return gcd(y, x % y);
}

int64_t abs(int64_t x) {
  return x < 0 ? -x : x;
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> X(N);
  std::vector<int64_t> Y(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> X.at(i) >> Y.at(i);
  }

  std::set<std::pair<int64_t, int64_t>> magic;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < N; j++) {
      if (i == j) continue;
      int64_t dx = X.at(i) - X.at(j);
      int64_t dy = Y.at(i) - Y.at(j);

      if (dx != 0 && dy != 0) {
        int64_t divider = gcd(abs(dx), abs(dy));
        dx /= divider;
        dy /= divider;
      } else {
        if (dx == 0) {
          dy /= abs(dy);
        } else {
          dx /= abs(dx);
        }
      }

      magic.insert(std::make_pair(dx, dy));
    }
  }

  std::cout << magic.size() << std::endl;

  return 0;
}
