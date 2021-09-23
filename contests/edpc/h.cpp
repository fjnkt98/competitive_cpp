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

  std::vector<std::vector<int64_t>> dp(H, std::vector<int64_t>(W, 0));
  dp.at(0).at(0) = 1;
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (i == 0 && j == 0) continue;
      if (grid.at(i).at(j) == '#') {
        dp.at(i).at(j) = 0;
        continue;
      }
      if (i == 0) {
        if (grid.at(i).at(j - 1) == '.') dp.at(i).at(j) += dp.at(i).at(j - 1);
      } else if (j == 0) {
        if (grid.at(i - 1).at(j) == '.') dp.at(i).at(j) += dp.at(i - 1).at(j);
      } else {
        if (grid.at(i).at(j - 1) == '.') dp.at(i).at(j) += dp.at(i).at(j - 1);
        if (grid.at(i - 1).at(j) == '.') dp.at(i).at(j) += dp.at(i - 1).at(j);
      }
      dp.at(i).at(j) = dp.at(i).at(j) % 1000000007;
    }
  }

  std::cout << dp.at(H - 1).at(W - 1) << std::endl;

  return 0;
}
