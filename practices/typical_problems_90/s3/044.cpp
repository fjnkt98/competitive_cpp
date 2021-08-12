#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;
  std::deque<int64_t> A;
  for (int64_t i = 0; i < N; i++) {
    int64_t a;
    std::cin >> a;
    A.push_back(a);
  }

  for (int64_t i = 0; i < Q; i++) {
    int64_t t, x, y;
    std::cin >> t >> x >> y;

    if (t == 1) {
      std::swap(A.at(x - 1), A.at(y - 1));
    } else if (t == 2) {
      A.push_front(A.back());
      A.pop_back();
    } else if (t == 3) {
      std::cout << A.at(x - 1) << std::endl;
    }
  }

  return 0;
}
