#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<int64_t>> masks(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t k;
    std::cin >> k;
    for (int64_t j = 0; j < k; j++) {
      int64_t b;
      std::cin >> b;

      masks.at(i).push_back(b);
    }
  }

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
        int64_t m;
        std::cin >> m;
        for (int64_t b : masks.at(m)) {
          x.set(b);
        }
        break;
      }
      case 2: {
        int64_t m;
        std::cin >> m;
        for (int64_t b : masks.at(m)) {
          x.set(b, false);
        }
        break;
      }
      case 3: {
        int64_t m;
        std::cin >> m;
        for (int64_t b : masks.at(m)) {
          x.flip(b);
        }
        break;
      }
      case 4: {
        int64_t m;
        std::cin >> m;
        bool ok = true;
        for (int64_t b : masks.at(m)) {
          if (!x.test(b)) ok = false;
        }

        std::cout << (ok ? 1 : 0) << std::endl;

        break;
      }
      case 5: {
        int64_t m;
        std::cin >> m;
        bool ok = false;
        for (int64_t b : masks.at(m)) {
          if (x.test(b)) ok = true;
        }

        std::cout << (ok ? 1 : 0) << std::endl;

        break;
      }
      case 6: {
        int64_t m;
        std::cin >> m;
        bool ok = true;
        for (int64_t b : masks.at(m)) {
          if (x.test(b)) ok = false;
        }

        std::cout << (ok ? 1 : 0) << std::endl;

        break;
      }
      case 7: {
        int64_t m;
        std::cin >> m;
        int64_t count = 0;
        for (int64_t b : masks.at(m)) {
          if (x.test(b)) count++;
        }

        std::cout << count << std::endl;

        break;
      }
      case 8: {
        int64_t m;
        std::cin >> m;
        std::bitset<64> mask(0);
        for (int64_t b : masks.at(m)) {
          mask.set(b);
        }

        std::cout << (x & mask).to_ullong() << std::endl;
        break;
      }
    }
  }

  return 0;
}