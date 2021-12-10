#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

int main() {
  int64_t Q;
  std::cin >> Q;
  std::deque<int64_t> A;
  for (int64_t i = 0; i < Q; i++) {
    int64_t t, d, x, p;
    std::cin >> t;

    switch (t) {
      case 0:
        std::cin >> d >> x;

        if (d == 0) {
          A.push_front(x);
        } else {
          A.push_back(x);
        }

        break;
      case 1:
        std::cin >> p;
        std::cout << A.at(p) << std::endl;
        break;
      case 2:
        std::cin >> d;

        if (d == 0) {
          A.pop_front();
        } else {
          A.pop_back();
        }

        break;
    }
  }

  return 0;
}
