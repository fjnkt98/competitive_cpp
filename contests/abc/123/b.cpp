#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<int64_t> X(5);
  for (int64_t i = 0; i < 5; i++) {
    std::cin >> X.at(i);
  }

  std::sort(X.begin(), X.end());

  int64_t answer = 1LL << 60;
  do {
    int64_t total_time = X.at(0);
    for (int64_t i = 1; i < 5; i++) {
      if (total_time % 10 != 0) {
        total_time = (total_time / 10 + 1) * 10;
      }
      total_time += X.at(i);
    }

    answer = std::min(answer, total_time);

  } while (std::next_permutation(X.begin(), X.end()));

  std::cout << answer << std::endl;

  return 0;
}
