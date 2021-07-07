#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, Y;
  std::cin >> N >> Y;

  for (int64_t i = 0; i <= N; i++) {
    for (int64_t j = 0; j <= (N - i); j++) {
      int64_t sum = 10000 * i + 5000 * j + 1000 * (N - i - j);

      if (sum == Y) {
        std::cout << i << " " << j << " " << (N - i - j) << std::endl;
        return 0;
      }
    }
  }

  std::cout << "-1 -1 -1" << std::endl;

  return 0;
}
