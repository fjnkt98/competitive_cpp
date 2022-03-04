#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <tuple>

int main() {
  int64_t Q;
  std::cin >> Q;
  std::vector<std::tuple<int64_t, int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t t;
    std::cin >> t;

    switch (t) {
      case 1: {
        int64_t x;
        std::cin >> x;
        query.at(i) = std::make_tuple(t, x, -1);
        break;
      }
      case 2: {
        int64_t x, k;
        std::cin >> x >> k;
        query.at(i) = std::make_tuple(t, x, k);
        break;
      }
      case 3: {
        int64_t x, k;
        std::cin >> x >> k;
        query.at(i) = std::make_tuple(t, x, k);
        break;
      }
    }
  }

  std::multiset<int64_t> A;
  for (int64_t i = 0; i < Q; i++) {
    auto [t, x, k] = query.at(i);

    switch (t) {
      case 1: {
        A.insert(x);
        break;
      }

      case 2: {
        auto iter = A.upper_bound(x);
        bool ok = true;
        for (int64_t j = 0; j < k; j++) {
          if (iter == A.begin()) {
            std::cout << -1 << std::endl;
            ok = false;
            break;
          } else {
            --iter;
          }
        }
        if (ok) std::cout << *iter << std::endl;
        break;
      }

      case 3: {
        auto iter = A.lower_bound(x);
        bool ok = true;
        for (int64_t j = 0; j < k; j++) {
          if (iter == A.end()) {
            std::cout << -1 << std::endl;
            ok = false;
            break;
          } else {
            ++iter;
          }
        }
        if (ok) {
          --iter;
          std::cout << *iter << std::endl;
        }
        break;
      }
    }
  }

  return 0;
}
