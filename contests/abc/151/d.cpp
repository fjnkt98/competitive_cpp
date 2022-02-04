#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
  int64_t H, W;
  std::cin >> H >> W;
  std::vector<std::string> maze(H);
  for (int64_t i = 0; i < H; i++) {
    std::cin >> maze.at(i);
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (maze.at(i).at(j) == '#') continue;

      std::vector<std::vector<int64_t>> distance(H,
                                                 std::vector<int64_t>(W, -1));
      std::queue<std::pair<int64_t, int64_t>> candidate;
      distance.at(i).at(j) = 0;
      candidate.push(std::make_pair(i, j));

      std::vector<int64_t> dr = {0, 1, 0, -1};
      std::vector<int64_t> dc = {1, 0, -1, 0};
      while (!candidate.empty()) {
        auto node = candidate.front();
        candidate.pop();
        int64_t r = node.first;
        int64_t c = node.second;

        for (int64_t k = 0; k < 4; k++) {
          int64_t next_row = r + dr.at(k);
          int64_t next_col = c + dc.at(k);

          if (next_row >= 0 && next_row < H && next_col >= 0 && next_col < W &&
              maze.at(next_row).at(next_col) == '.' &&
              distance.at(next_row).at(next_col) == -1) {
            distance.at(next_row).at(next_col) = distance.at(r).at(c) + 1;
            candidate.push(std::make_pair(next_row, next_col));
          }
        }
      }

      for (auto r : distance) {
        for (auto c : r) {
          answer = std::max(answer, c);
        }
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
