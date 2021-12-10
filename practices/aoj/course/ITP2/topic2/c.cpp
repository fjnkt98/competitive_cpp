#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;

  std::vector<std::tuple<int64_t, int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t q, t, x;
    std::cin >> q;
    switch (q) {
      case 0:
        std::cin >> t >> x;
        query.at(i) = std::make_tuple(q, t, x);
        break;
      case 1:
        std::cin >> t;
        query.at(i) = std::make_tuple(q, t, x);
        break;
      case 2:
        std::cin >> t;
        query.at(i) = std::make_tuple(q, t, x);
        break;
    }
  }

  std::vector<std::priority_queue<int64_t>> A(N);
  for (int64_t i = 0; i < Q; i++) {
    int64_t q = std::get<0>(query.at(i));
    int64_t t = std::get<1>(query.at(i));
    int64_t x = std::get<2>(query.at(i));

    switch (q) {
      case 0:
        A.at(t).push(x);
        break;
      case 1:
        if (!A.at(t).empty()) {
          std::cout << A.at(t).top() << std::endl;
        }
        break;
      case 2:
        if (!A.at(t).empty()) {
          A.at(t).pop();
        }
        break;
    }
  }

  return 0;
}
