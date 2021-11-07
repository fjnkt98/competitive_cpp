#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<int64_t> A(3);
  for (int64_t i = 0; i < 3; i++) {
    std::cin >> A.at(i);
  }
  std::sort(A.begin(), A.end());
  int64_t K;
  std::cin >> K;

  for (int64_t i = 0; i < K; i++) {
    A.back() *= 2;
  }

  std::cout << A.at(0) + A.at(1) + A.at(2) << std::endl;

  return 0;
}
