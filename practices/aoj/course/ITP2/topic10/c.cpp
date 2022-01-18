#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t Q;
  std::cin >> Q;

  std::bitset<64> x(0);

  for (int64_t i = 0; i < Q; i++) {
    int64_t t;
    std::cin >> t;

    switch (t) {
      case 0: {
        int64_t i;
        std::cin >> i;
        std::cout << (x.test(i) ? 1 : 0) << std::endl;

        break;
      }

      case 1: {
        int64_t i;
        std::cin >> i;
        x.set(i, true);
        break;
      }
      case 2: {
        int64_t i;
        std::cin >> i;
        x.set(i, false);
        break;
      }
      case 3: {
        int64_t i;
        std::cin >> i;
        x.flip(i);
        break;
      }
      case 4: {
        std::cout << (x.all() ? 1 : 0) << std::endl;
        break;
      }
      case 5: {
        std::cout << (x.any() ? 1 : 0) << std::endl;
        break;
      }
      case 6: {
        std::cout << (x.none() ? 1 : 0) << std::endl;
        break;
      }
      case 7: {
        std::cout << x.count() << std::endl;
        break;
      }
      case 8: {
        std::cout << x.to_ullong() << std::endl;
        break;
      }
    }
  }

  return 0;
}