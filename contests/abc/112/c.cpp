#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::tuple<int64_t, int64_t, int64_t>> input(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t x, y, h;
    std::cin >> x >> y >> h;

    input.at(i) = std::make_tuple(x, y, h);
  }

  for (int64_t cx = 0; cx <= 100; cx++) {
    for (int64_t cy = 0; cy <= 100; cy++) {
      bool ok = true;
      int64_t H = -1;

      for (int64_t i = 0; i < N; i++) {
        auto [x, y, h] = input.at(i);

        if (h == 0) continue;

        H = h + std::abs(x - cx) + std::abs(y - cy);
      }

      for (int64_t i = 0; i < N; i++) {
        auto [x, y, h] = input.at(i);

        if (std::max(H - std::abs(x - cx) - std::abs(y - cy), 0L) != h) {
          ok = false;
        }
      }

      if (ok) {
        std::cout << cx << " " << cy << " " << H << std::endl;
        return 0;
      }
    }
  }

  return 0;
}