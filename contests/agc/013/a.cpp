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

  int64_t answer = 0;
  int64_t current_minimum = 1LL << 60;
  int64_t current_maximum = -1;
  for (int64_t i = 0; i < N; i++) {
    if (A.at(i) < current_maximum || A.at(i) > current_minimum) {
      answer++;
      current_minimum = 1LL << 60;
      current_maximum = -1;
    } else {
      if (A.at(i) >= current_maximum) {
        current_maximum = A.at(i);
      } else if (A.at(i) <= current_minimum) {
        current_minimum = A.at(i);
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}