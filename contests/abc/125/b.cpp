#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> V(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> V.at(i);
  }
  std::vector<int64_t> C(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> C.at(i);
  }

  int64_t answer = 0;
  for (int64_t bit = 0; bit < (1 << N); bit++) {
    int64_t value = 0;
    int64_t cost = 0;
    for (int64_t i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        value += V.at(i);
        cost += C.at(i);
      }
    }

    answer = std::max(answer, value - cost);
  }

  std::cout << answer << std::endl;

  return 0;
}
