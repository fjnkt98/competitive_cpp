#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <tuple>

int main() {
  int64_t Q;
  std::cin >> Q;
  std::vector<std::tuple<int64_t, int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t t = -1;
    int64_t x = -1;
    int64_t d = -1;

    std::cin >> t;

    switch (t) {
      case 0:
        std::cin >> x;
        query.at(i) = std::make_tuple(t, x, d);
        break;
      case 1:
        std::cin >> d;
        query.at(i) = std::make_tuple(t, x, d);
        break;
      case 2:
        query.at(i) = std::make_tuple(t, x, d);
        break;
    }
  }

  std::list<int64_t> A;
  auto iter = A.end();
  for (int64_t i = 0; i < Q; i++) {
    int64_t t = std::get<0>(query.at(i));
    int64_t x = std::get<1>(query.at(i));
    int64_t d = std::get<2>(query.at(i));

    switch (t) {
      case 0:
        iter = A.insert(iter, x);
        break;
      case 1:
        std::advance(iter, d);

        break;
      case 2:
        iter = A.erase(iter);
        break;
    }
  }

  for (auto iter = A.begin(); iter != A.end(); iter++) {
    std::cout << *iter << std::endl;
  }

  return 0;
}
