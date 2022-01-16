#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  int64_t Q;
  std::cin >> Q;
  std::map<std::string, int64_t> map;
  for (int64_t i = 0; i < Q; i++) {
    int64_t t, x;
    std::string s;
    std::cin >> t;

    switch (t) {
      case 0:
        std::cin >> s >> x;
        map[s] = x;

        break;
      case 1:
        std::cin >> s;
        std::cout << map[s] << std::endl;
        break;
      case 2:
        std::cin >> s;
        map.erase(s);
        break;
    }
  }

  return 0;
}