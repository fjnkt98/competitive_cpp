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
  for (int64_t i = 0; i < N; i++) {
    std::cin >> B.at(i);
  }

  /* int64_t count = B.at(0) - A.at(0) + 1; */
  int64_t answer = 1;
  for (int64_t i = 1; i < N; i++) {
    int64_t count = 0;
    for (int64_t j = A.at(i - 1); j <= B.at(i - 1); j++) {
      for (int64_t k = j; k <= B.at(i); k++) {
        count++;
      }
    }

    answer *= count;
    answer = answer % 998244353;
  }

  std::cout << answer << std::endl;

  return 0;
}
