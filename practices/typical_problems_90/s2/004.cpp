#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t H, W;
  std::cin >> H >> W;

  std::vector<std::vector<int64_t>> grid(H + 1, std::vector<int64_t>(W + 1));
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      std::cin >> grid.at(i).at(j);
    }
  }

  for (int64_t i = 0; i < H; i++) {
    int64_t sum_of_row = 0;
    for (int64_t j = 0; j < W; j++) {
      sum_of_row += grid.at(i).at(j);
    }
    grid.at(i).at(W) = sum_of_row;
  }

  for (int64_t j = 0; j <= W; j++) {
    int64_t sum_of_column = 0;
    for (int64_t i = 0; i < H; i++) {
      sum_of_column += grid.at(i).at(j);
    }
    grid.at(H).at(j) = sum_of_column;
  }

  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (j) std::cout << " ";
      std::cout << grid.at(i).at(W) + grid.at(H).at(j) - grid.at(i).at(j);
    }
    std::cout << std::endl;
  }

  return 0;
}
