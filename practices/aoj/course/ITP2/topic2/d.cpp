#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <list>

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
        std::cin >> t >> x;
        query.at(i) = std::make_tuple(q, t, x);
        break;
    }
  }

  std::vector<std::list<int64_t>> A(N);
  for (int64_t i = 0; i < Q; i++) {
    int64_t q = std::get<0>(query.at(i));
    int64_t t = std::get<1>(query.at(i));
    int64_t x = std::get<2>(query.at(i));

    switch (q) {
      case 0:
        A.at(t).insert(A.at(t).end(), x);
        break;
      case 1:
        for (auto iter = A.at(t).begin(); iter != A.at(t).end(); iter++) {
          if (iter != A.at(t).begin()) std::cout << " ";
          std::cout << *iter;
        }
        std::cout << std::endl;
        break;
      case 2:
        A.at(x).splice(A.at(x).end(), A.at(t));
        A.at(t).clear();
        break;
    }
  }

  return 0;
}
