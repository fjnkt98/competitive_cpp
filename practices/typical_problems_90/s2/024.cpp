#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;

  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  for (int64_t i = 0; i < N; i++) {
    std::cin >> B.at(i);
  }

  for (int64_t i = 0; i < N; i++) {
    K -= std::abs(A.at(i) - B.at(i));
  }

  if (K < 0) {
    std::cout << "No" << std::endl;
  } else if (K % 2 == 0) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
}
