#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t q;
  std::cin >> q;
  std::vector<int64_t> result;
  for (int64_t i = 0; i < q; i++) {
    int64_t xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3;
    std::cin >> xp0 >> yp0 >> xp1 >> yp1 >> xp2 >> yp2 >> xp3 >> yp3;

    if ((yp1 - yp0) * (xp3 - xp2) == (yp3 - yp2) * (xp1 - xp0)) {
      result.push_back(2);
    } else if ((yp1 - yp0) * (yp3 - yp2) == -((xp1 - xp0) * (xp3 - xp2))) {
      result.push_back(1);
    } else {
      result.push_back(0);
    }
  }

  for (auto r : result) {
    std::cout << r << std::endl;
  }

  return 0;
}