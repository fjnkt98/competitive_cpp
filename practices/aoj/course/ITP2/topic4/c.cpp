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
    int64_t b, e, t;
    std::cin >> b >> e >> t;

    for (int64_t k = 0; k < (e - b); k++) {
      std::swap(A.at(b + k), A.at(t + k));
    }
  }

  for (int64_t i = 0; i < N; i++) {
    if (i) std::cout << " ";
    std::cout << A.at(i);
  }
  std::cout << std::endl;

  return 0;
}
