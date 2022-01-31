#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> X(N, 0);
  for (int64_t i = 0; i < N; i++) {
    if (i % 2 == 0) {
      X.at(0) += A.at(i);
    } else {
      X.at(0) -= A.at(i);
    }
  }

  for (int64_t i = 1; i < N; i++) {
    X.at(i) = 2 * A.at(i - 1) - X.at(i - 1);
  }

  for (int64_t i = 0; i < N; i++) {
    if (i) std::cout << " ";
    std::cout << X.at(i);
  }
  std::cout << std::endl;

  return 0;
}