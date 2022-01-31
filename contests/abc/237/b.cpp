#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t H, W;
  std::cin >> H >> W;
  std::vector<std::vector<int64_t>> A(H, std::vector<int64_t>(W));
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      std::cin >> A.at(i).at(j);
    }
  }

  std::vector<std::vector<int64_t>> B(W, std::vector<int64_t>(H));
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      B.at(j).at(i) = A.at(i).at(j);
    }
  }

  for (int64_t i = 0; i < W; i++) {
    for (int64_t j = 0; j < H; j++) {
      if (j) std::cout << " ";
      std::cout << B.at(i).at(j);
    }
    std::cout << std::endl;
  }

  return 0;
}
