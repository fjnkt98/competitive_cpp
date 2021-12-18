#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t H, W, N;
  std::cin >> H >> W >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> ink(H * W);
  int64_t index = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < A.at(i); j++) {
      ink.at(index) = i + 1;
      index++;
    }
  }

  std::vector<std::vector<int64_t>> grid(H, std::vector<int64_t>(W));
  index = 0;
  for (int64_t i = 0; i < H; i++) {
    if (i % 2 == 0) {
      for (int64_t j = 0; j < W; j++) {
        grid.at(i).at(j) = ink.at(index);
        index++;
      }
    } else {
      for (int64_t j = W - 1; j >= 0; j--) {
        grid.at(i).at(j) = ink.at(index);
        index++;
      }
    }
  }

  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      std::cout << grid.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }

}
