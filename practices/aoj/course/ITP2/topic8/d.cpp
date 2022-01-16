#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  int64_t Q;
  std::cin >> Q;
  std::multimap<std::string, int64_t> map;
  for (int64_t i = 0; i < Q; i++) {
    int64_t t;
    std::cin >> t;

    switch (t) {
      case 0: {
        std::string key;
        int64_t x;
        std::cin >> key >> x;
        map.insert(std::make_pair(key, x));

        break;
      }
      case 1: {
        std::string key;
        std::cin >> key;
        auto range = map.equal_range(key);
        for (auto iter = range.first; iter != range.second; iter++) {
          std::cout << iter->second << std::endl;
        }
        break;
      }
      case 2: {
        std::string key;
        std::cin >> key;
        map.erase(key);
        break;
      }
      case 3: {
        std::string l, r;
        std::cin >> l >> r;

        auto left = map.lower_bound(l);
        auto right = map.upper_bound(r);

        for (auto iter = left; iter != right; iter++) {
          if (iter->second == 0) continue;
          std::cout << iter->first << " " << iter->second << std::endl;
        }
        break;
      }
    }
  }

  return 0;
}