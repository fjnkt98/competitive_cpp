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

  int64_t valid_number = 1;
  int64_t unbreak_bricks = 0;
  for (int64_t i = 0; i < N; i++) {
    if (A.at(i) == valid_number) {
      unbreak_bricks++;
      valid_number++;
    }
  }

  if (unbreak_bricks == 0) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << N - unbreak_bricks << std::endl;
  }

  return 0;
}
