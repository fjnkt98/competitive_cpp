#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdint>

const int64_t INF = 1LL << 60;

int main() {
  int64_t H, W, C;
  std::cin >> H >> W >> C;
  std::vector<std::vector<int64_t>> A(H, std::vector<int64_t>(W));
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      std::cin >> A.at(i).at(j);
    }
  }

  // DP table for left to right search
  std::vector<std::vector<int64_t>> dp(H + 1, std::vector<int64_t>(W + 1, INF));

  int64_t minimum_cost = INF;
  // DP start(left to right search)
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      dp.at(i + 1).at(j + 1) = std::min(
          A.at(i).at(j),
          std::min(
            dp.at(i).at(j + 1) + C,
            dp.at(i + 1).at(j) + C
            )
          );
      int64_t X = std::min(
          dp.at(i).at(j + 1) + C + A.at(i).at(j),
          dp.at(i + 1).at(j) + C + A.at(i).at(j)
          );
      if (X < minimum_cost) {
        minimum_cost = X;
      }
    }
  }

  // DP table for right to left search
  for (int64_t i = 0; i < H + 1; i++) {
    dp.at(i).assign(W + 1, INF);
  }
  // DP start(right to left search)
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = W - 1; j >= 0; j--) {
      dp.at(i + 1).at(j) = std::min(
          A.at(i).at(j),
          std::min(
            dp.at(i).at(j) + C,
            dp.at(i + 1).at(j + 1) + C
            )
          );
      int64_t X = std::min(
          dp.at(i).at(j) + C + A.at(i).at(j),
          dp.at(i + 1).at(j + 1) + C + A.at(i).at(j)
          );
      if (X < minimum_cost) {
        minimum_cost = X;
      }
    }
  }

  std::cout << minimum_cost << std::endl;

  return 0;
}
