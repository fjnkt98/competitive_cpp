#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > 100) {
    std::cout << "No" << std::endl;
    return 0;
  }

  std::vector<int64_t> dx = {2, 1, -1, -2, -2, -1, 1, 2};
  std::vector<int64_t> dy = {1, 2, 2, 1, -1, -2, -2, -1};

  bool ok = false;
  for (int64_t i = 0; i < 8; i++) {
    int64_t x = x1 + dx.at(i);
    int64_t y = y1 + dy.at(i);

    int64_t diff2 = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
    if (diff2 == 5) {
      ok = true;
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
