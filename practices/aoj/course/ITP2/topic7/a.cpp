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
    int64_t t, x;
    std::cin >> t >> x;

    if (t == 0) {
      set.insert(x);
      std::cout << set.size() << std::endl;
    } else {
      if (set.find(x) == set.end()) {
        std::cout << 0 << std::endl;
      } else {
        std::cout << 1 << std::endl;
      }
    }
  }

  return 0;
}