#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
  int64_t Q;
  std::cin >> Q;
  std::set<int64_t> set;
  for (int64_t i = 0; i < Q; i++) {
    int64_t t, x, l, r;
    std::cin >> t;

    switch (t) {
      case 0:
        std::cin >> x;
        set.insert(x);
        std::cout << set.size() << std::endl;
        break;
      case 1:
        std::cin >> x;
        std::cout << (set.find(x) == set.end() ? 0 : 1) << std::endl;
        break;
      case 2:
        std::cin >> x;
        set.erase(x);
        break;
      case 3:
        std::cin >> l >> r;

        auto left = set.lower_bound(l);
        auto right = set.upper_bound(r);

        for (auto iter = left; iter != right; iter++) {
          std::cout << *iter << std::endl;
        }
        break;
    }
  }

  return 0;
}