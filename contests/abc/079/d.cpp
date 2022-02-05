#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t H, W;
  std::cin >> H >> W;
  std::vector<std::vector<int64_t>> C(10, std::vector<int64_t>(10));
  std::vector<std::vector<int64_t>> dp(10, std::vector<int64_t>(10, 1LL << 60));
  for (int64_t i = 0; i < 10; i++) {
    for (int64_t j = 0; j < 10; j++) {
      int64_t c;
      std::cin >> c;
      C.at(i).at(j) = c;
      dp.at(i).at(j) = c;
    }
  }

  std::vector<std::vector<int64_t>> A(H, std::vector<int64_t>(W));
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      std::cin >> A.at(i).at(j);
    }
  }

  for (int64_t i = 0; i < 10; i++) {
    dp.at(i).at(i) = 0;
  }

  for (int64_t k = 0; k < 10; k++) {
    for (int64_t i = 0; i < 10; i++) {
      for (int64_t j = 0; j < 10; j++) {
        dp.at(i).at(j) =
            std::min(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k).at(j));
      }
    }
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (A.at(i).at(j) == -1) continue;
      answer += dp.at(A.at(i).at(j)).at(1);
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
