#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, X;
  std::cin >> N >> X;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> B;
  for (int64_t i = 0; i < N; i++) {
    if (A.at(i) != X) B.push_back(A.at(i));
  }

  for (size_t i = 0; i < B.size(); i++) {
    if (i) std::cout << " ";
    std::cout << B.at(i);
  }
  std::cout << std::endl;

  return 0;
}
