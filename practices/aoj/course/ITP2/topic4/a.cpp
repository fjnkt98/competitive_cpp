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
    int64_t b, e;
    std::cin >> b >> e;

    auto begin = std::next(A.begin(), b);
    auto end = std::next(A.begin(), e);

    std::reverse(begin, end);
  }

  for (size_t i = 0; i < A.size(); i++) {
    if (i) std::cout << " ";
    std::cout << A.at(i);
  }
  std::cout << std::endl;

  return 0;
}
