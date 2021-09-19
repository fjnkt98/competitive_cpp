#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t H, W;
  std::cin >> H >> W;

  std::vector<std::string> grid(H);
  for (int64_t i = 0; i < H; i++) {
    std::cin >> grid.at(i);
  }

  int64_t N = 0;

  std::vector<int64_t> dr = {0, 1, 1, 0};
  std::vector<int64_t> dc = {0, 0, 1, 1};

  for (int64_t i = 0; i < H - 1; i++) {
    for (int64_t j = 0; j < W - 1; j++) {
      int64_t count = 0;
      for (int64_t k = 0; k < 4; k++) {
        if (grid.at(i + dr.at(k)).at(j + dc.at(k)) == '#') {
          count++;
        }
      }

      if (count % 2 != 0) N++;
    }
  }

  std::cout << N << std::endl;

  return 0;
}
