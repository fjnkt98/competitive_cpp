#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t W, H, N;
  std::cin >> W >> H >> N;

  std::vector<std::vector<int64_t>> grid(H, std::vector<int64_t>(W, 0));
  for (int64_t i = 0; i < N; i++) {
    int64_t x, y, a;
    std::cin >> x >> y >> a;

    switch (a) {
      case 1:
        for (int64_t i = 0; i < H; i++) {
          for (int64_t j = 0; j < x; j++) {
            grid.at(i).at(j) = 1;
          }
        }
        break;
      case 2:
        for (int64_t i = 0; i < H; i++) {
          for (int64_t j = x; j < W; j++) {
            grid.at(i).at(j) = 1;
          }
        }
        break;
      case 3:
        for (int64_t j = 0; j < W; j++) {
          for (int64_t i = 0; i < y; i++) {
            grid.at(i).at(j) = 1;
          }
        }
        break;
      case 4:
        for (int64_t j = 0; j < W; j++) {
          for (int64_t i = y; i < H; i++) {
            grid.at(i).at(j) = 1;
          }
        }
        break;
    }
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (grid.at(i).at(j) == 0) {
        answer++;
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
