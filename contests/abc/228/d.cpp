#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  const int64_t mod = 1048576;
  int64_t Q;
  std::cin >> Q;
  std::vector<std::pair<int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t t, x;
    std::cin >> t >> x;
    query.at(i) = std::make_pair(t, x);
  }

  std::vector<int64_t> A(mod, -1);
  std::set<int64_t> target;
  for (int64_t i = 0; i < mod; i++) {
    target.insert(i);
  }

  for (int64_t i = 0; i < Q; i++) {
    int64_t t = query.at(i).first;
    int64_t x = query.at(i).second;

    if (t == 1) {
      int64_t h = x;
      if (A.at(h % mod) == -1) {
        A.at(h % mod) = x;
        target.erase(h % mod);
      } else {
        auto iter = target.upper_bound(h % mod);
        int64_t index = 0;
        if (iter == target.end()) {
          index = *target.begin();
        } else {
          index = *iter;
        }

        A.at(index) = x;
        target.erase(index);
      }
    } else {
      std::cout << A.at(x % mod) << std::endl;
    }
  }

  return 0;
}
