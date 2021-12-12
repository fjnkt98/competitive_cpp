#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  std::vector<int64_t> X(Q);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> X.at(i);
  }

  std::sort(A.begin(), A.end());

  for (int64_t i = 0; i < Q; i++) {
    auto iter = std::lower_bound(A.begin(), A.end(), X.at(i));

    std::cout << std::distance(iter, A.end()) << std::endl;
  }

  return 0;
}
