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
    int64_t k;
    std::cin >> k;

    std::cout << std::distance(A.begin(), std::lower_bound(A.begin(), A.end(), k)) << std::endl;
  }

  return 0;
}