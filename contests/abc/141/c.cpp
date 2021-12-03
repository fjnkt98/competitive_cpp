#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K, Q;
  std::cin >> N >> K >> Q;
  std::vector<int64_t> A(Q);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> point(N, K);
  for (int64_t i = 0; i < Q; i++) {
    point.at(A.at(i) - 1)++;
  }
  for (int64_t i = 0; i < N; i++) {
    point.at(i) -= Q;
  }

  std::vector<bool> qualified(N, true);
  for (int64_t i = 0; i < N; i++) {
    if (point.at(i) <= 0) {
      qualified.at(i) = false;
    }
  }

  /* for (auto p : point) { */
  /*   std::cout << p << std::endl; */
  /* } */

  for (int64_t i = 0; i < N; i++) {
    if (qualified.at(i)) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }

  return 0;
}
