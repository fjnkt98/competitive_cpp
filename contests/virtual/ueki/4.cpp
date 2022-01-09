#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t H, W, N, M;
  std::cin >> H >> W >> N >> M;

  std::vector<std::vector<int64_t>> grid1(H, std::vector<int64_t>(W, -1));
  std::vector<std::vector<int64_t>> grid2(H, std::vector<int64_t>(W, -1));

  std::vector<std::pair<int64_t, int64_t>> light(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    light.at(i) = std::make_pair(a - 1, b - 1);
  }
  std::vector<std::pair<int64_t, int64_t>> block(M);
  for (int64_t i = 0; i < M; i++) {
    int64_t c, d;
    std::cin >> c >> d;
    block.at(i) = std::make_pair(c - 1, d - 1);
    grid1.at(c - 1).at(d - 1) = 0;
    grid2.at(c - 1).at(d - 1) = 0;
  }

  for (int64_t i = 0; i < N; i++) {
    int64_t r = light.at(i).first;
    int64_t c = light.at(i).second;

    if (grid1.at(r).at(c) == 1) continue;

    grid1.at(r).at(c) = 1;
    for (int64_t dr : {-1, 1}) {
      int64_t next_r = r + dr;
      while (next_r >= 0 && next_r < H && grid1.at(next_r).at(c) != 0) {
        grid1.at(next_r).at(c) = 1;
        next_r += dr;
      }
    }
  }

  for (int64_t i = 0; i < N; i++) {
    int64_t r = light.at(i).first;
    int64_t c = light.at(i).second;

    if (grid2.at(r).at(c) == 1) continue;

    grid2.at(r).at(c) = 1;
    for (int64_t dc : {-1, 1}) {
      int64_t next_c = c + dc;
      while (next_c >= 0 && next_c < W && grid2.at(r).at(next_c) != 0) {
        grid2.at(r).at(next_c) = 1;
        next_c += dc;
      }
    }
  }

  // for (auto r : grid1) {
  //   for (auto c : r) {
  //     std::cout << c << " ";
  //   }
  //   std::cout << std::endl;
  // }
  // for (auto r : grid2) {
  //   for (auto c : r) {
  //     std::cout << c << " ";
  //   }
  //   std::cout << std::endl;
  // }

  int64_t answer = 0;
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (grid1.at(i).at(j) == 1 || grid2.at(i).at(j) == 1) {
        answer++;
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}