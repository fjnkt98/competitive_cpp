#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
  int64_t H, W, K;
  std::cin >> H >> W >> K;

  std::vector<std::string> grid(H);
  for (int64_t i = 0; i < H; i++) {
    std::cin >> grid.at(i);
  }

  std::vector<std::vector<int64_t>> answer(H, std::vector<int64_t>(W, 0));
  int64_t index = 1;
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (grid.at(i).at(j) == '#') {
        answer.at(i).at(j) = index;
        index++;
      }
    }
  }

  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (j != 0 && answer.at(i).at(j) == 0) {
        answer.at(i).at(j) = answer.at(i).at(j - 1);
      }
    }

    for (int64_t j = W - 1; j >= 0; j--) {
      if (j != W - 1 && answer.at(i).at(j) == 0) {
        answer.at(i).at(j) = answer.at(i).at(j + 1);
      }
    }
  }

  for (int64_t j = 0; j < W; j++) {
    for (int64_t i = 0; i < H; i++) {
      if (i != 0 && answer.at(i).at(j) == 0) {
        answer.at(i).at(j) = answer.at(i - 1).at(j);
      }
    }

    for (int64_t i = H - 1; i >= 0; i--) {
      if (i != H - 1 && answer.at(i).at(j) == 0) {
        answer.at(i).at(j) = answer.at(i + 1).at(j);
      }
    }
  }

  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (j) std::cout << " ";
      std::cout << answer.at(i).at(j);
    }
    std::cout << std::endl;
  }

  return 0;
}