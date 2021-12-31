#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t Q;
  std::cin >> Q;
  for (int64_t i = 0; i < Q; i++) {
    int64_t c, b, e;
    std::cin >> c >> b >> e;

    if (c == 0) {
      int64_t min = *std::min_element(std::next(A.begin(), b), std::next(A.begin(), e));

      std::cout << min << std::endl;
    } else {
      int64_t max = *std::max_element(std::next(A.begin(), b), std::next(A.begin(), e));

      std::cout << max << std::endl;
    }
  }

  return 0;
}
