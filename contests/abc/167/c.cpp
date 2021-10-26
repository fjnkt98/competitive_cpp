#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M, X;
  std::cin >> N >> M >> X;
  std::vector<int64_t> C(N);
  std::vector<std::vector<int64_t>> A(N, std::vector<int64_t>(M));
  for (int64_t i = 0; i < N; i++) {
    std::cin >> C.at(i);
    for (int64_t j = 0; j < M; j++) {
      std::cin >> A.at(i).at(j);
    }
  }

  int64_t minimum_price = 1LL << 60;
  for (int64_t bit = 0; bit < (1 << N); bit++) {
    int64_t price = 0;
    std::vector<int64_t> comprehension(M, 0);

    for (int64_t i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        for (int64_t j = 0; j < M; j++) {
          comprehension.at(j) += A.at(i).at(j);
        }
        price += C.at(i);
      }
    }
    /* std::cout << price << std::endl; */
    /* for (int64_t c : comprehension) { */
    /*   std::cout << c << " "; */
    /* } */
    /* std::cout << std::endl; */

    bool ok = true;
    for (int64_t i = 0; i < M; i++) {
      if (comprehension.at(i) < X) {
        ok = false;
      }
    }

    if (ok) {
      minimum_price = std::min(minimum_price, price);
    }
  }

  if (minimum_price == 1LL << 60) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << minimum_price << std::endl;
  }

  return 0;
}
