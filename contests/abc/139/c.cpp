#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> H(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> H.at(i);
  }

  int64_t current_step = 0;
  std::vector<int64_t> step(N, 0);
  for (int64_t i = N - 2; i >= 0; i--) {
    if (H.at(i) >= H.at(i + 1)) {
      current_step++;
    } else {
      current_step = 0;
    }

    step.at(i) = current_step;
  }

  std::cout << *std::max_element(step.begin(), step.end()) << std::endl;

  return 0;
}
