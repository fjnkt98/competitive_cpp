#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<std::pair<int64_t, int64_t>>> claim(
      N, std::vector<std::pair<int64_t, int64_t>>());

  for (int64_t i = 0; i < N; i++) {
    int64_t A;
    std::cin >> A;
    for (int64_t j = 0; j < A; j++) {
      int64_t x, y;
      std::cin >> x >> y;
      claim.at(i).push_back(std::make_pair(x - 1, y));
    }
  }

  int64_t answer = -1;
  for (int64_t bit = 0; bit < (1 << N); bit++) {
    bool ok = true;

    for (int64_t i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        for (auto c : claim.at(i)) {
          int64_t x = c.first;
          int64_t y = c.second;

          if (((bit >> x) & 1) ^ y) {
            ok = false;
          }
        }
      }
    }

    if (ok) {
      int64_t honest = 0;
      for (int64_t i = 0; i < N; i++) {
        if (bit & (1 << i)) {
          honest++;
        }
      }
      answer = std::max(answer, honest);
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
