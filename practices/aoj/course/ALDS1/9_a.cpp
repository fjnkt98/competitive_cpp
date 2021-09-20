#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> A.at(i);
  }

  for (int64_t i = 1; i <= N; i++) {
    if (i == 1) {
      std::cout << "node " << i <<  ": key = " << A.at(i) << ", ";
      if (2 * i <= N) std::cout << "left key = " << A.at(2 * i) << ", ";
      if (2 * i + 1 <= N) std::cout << "right key = " << A.at(2 * i + 1) << ", ";
      std::cout << std::endl;
    } else {
      std::cout << "node " << i <<  ": key = " << A.at(i) << ", ";
      std::cout << "parent key = " << A.at(i / 2) << ", ";
      if (2 * i <= N) std::cout << "left key = " << A.at(2 * i) << ", ";
      if (2 * i + 1 <= N) std::cout << "right key = " << A.at(2 * i + 1) << ", ";
      std::cout << std::endl;
    }
  }

  return 0;
}
