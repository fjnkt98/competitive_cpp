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
    int64_t b, m, e;
    std::cin >> b >> m >> e;
    std::vector<int64_t> B(N);
    std::copy(A.begin(), A.end(), B.begin());

    for (int64_t k = 0; k < (e - b); k++) {
      B.at(b + ((k + (e - m)) % (e - b))) = A.at(b + k);
    }

    std::copy(B.begin(), B.end(), A.begin());
  }

  for (size_t j = 0; j < A.size(); j++) {
    if (j) std::cout << " ";
    std::cout << A.at(j);
  }
  std::cout << std::endl;

  return 0;
}
