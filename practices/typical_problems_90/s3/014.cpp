#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (auto& a : A) {
    std::cin >> a;
  }
  std::vector<int64_t> B(N);
  for (auto& b : B) {
    std::cin >> b;
  }

  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());

  int64_t complain_level = 0;
  for (int64_t i = 0; i < N; i++) {
    complain_level += std::abs(A.at(i) - B.at(i));
  }

  std::cout << complain_level << std::endl;

  return 0;
}
