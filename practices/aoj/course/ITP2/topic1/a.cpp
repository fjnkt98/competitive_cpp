#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t Q;
  std::cin >> Q;
  std::vector<int64_t> A;
  for (int64_t i = 0; i < Q; i++) {
    int64_t t;
    std::cin >> t;

    switch (t) {
      case 0:
        int64_t x;
        std::cin >> x;

        A.push_back(x);
        break;
      case 1:
        int64_t p;
        std::cin >> p;
        std::cout << A.at(p) << std::endl;
        break;
      case 2:
        A.pop_back();
        break;
    }
  }

  return 0;
}
