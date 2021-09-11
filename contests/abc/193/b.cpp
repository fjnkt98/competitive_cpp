#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> A(N);
  std::vector<int64_t> P(N);
  std::vector<int64_t> X(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i) >> P.at(i) >> X.at(i);
  }

  int64_t minimum_price = 1LL << 60;

  for (int64_t i = 0; i < N; i++) {
    if (A.at(i) < X.at(i)) {
      minimum_price = std::min(minimum_price, P.at(i));
    }
  }

  if (minimum_price == 1LL << 60) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << minimum_price << std::endl;
  }

  return 0;
}
