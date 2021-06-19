/*
 * Subset problem
 *
 * Solving by bit full search.
 */

#include <iostream>
#include <vector>

int main() {
  int64_t N;
  int64_t W;

  std::cin >> N >> W;

  std::vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  bool satisfy = false;

  for (int64_t bit = 0; bit < (1 << N); bit++) {
    int64_t sum = 0;
    for (int64_t i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        sum += a.at(i);
      }
    }

    if (sum == W) {
      satisfy = true;
    }
  }

  if (satisfy) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}
