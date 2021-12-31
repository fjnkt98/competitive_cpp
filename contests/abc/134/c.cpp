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

  std::vector<int64_t> B(N);
  std::copy(A.begin(), A.end(), B.begin());
  std::sort(B.begin(), B.end());

  int64_t max = B.back();

  for (int64_t i = 0; i < N; i++) {
    if (A.at(i) == max) {
      std::cout << B.at(N - 2) << std::endl;
    } else {
      std::cout << max << std::endl;
    }
  }

  return 0;
}
