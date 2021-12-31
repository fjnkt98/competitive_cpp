#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> boxes(N + 1);

  for (int64_t i = N; i >= 1; i--) {
    int64_t sum = 0;
    for (int64_t j = i; j <= N; j += i) {
      sum += boxes.at(j);
    }

    if (sum % 2 != A.at(i)) {
      boxes.at(i) = 1;
    }
  }

  bool ok = true;
  for (int64_t i = 1; i <= N; i++) {
    int64_t sum = 0;
    for (int64_t j = i; j <= N; j += i) {
      sum += boxes.at(j);
    }

    if (sum % 2 != A.at(i)) {
      ok = false;
    }
  }

  if (ok) {
    int64_t M = 0;
    std::vector<int64_t> B;

    for (int64_t i = 1; i <= N; i++) {
      if (boxes.at(i) == 1) {
        M++;
        B.push_back(i);
      }
    }

    std::cout << M << std::endl;
    for (size_t i = 0; i < B.size(); i++) {
      if (i) std::cout << " ";
      std::cout << B.at(i);
    }
    std::cout << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }

  return 0;
}
