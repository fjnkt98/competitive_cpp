#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  int64_t L, Q;
  std::cin >> L >> Q;
  std::vector<int64_t> c(Q);
  std::vector<int64_t> x(Q);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> c.at(i) >> x.at(i);
  }

  std::set<int64_t> cutted;
  cutted.insert(0);
  cutted.insert(L);

  for (int64_t i = 0; i < Q; i++) {
    switch (c.at(i)) {
      case 1:
        cutted.insert(x.at(i));
        break;
      case 2:
        auto iter = cutted.lower_bound(x.at(i));
        int64_t length = *iter - *(--iter);
        std::cout << length << std::endl;
        break;
    }
  }

  return 0;
}
