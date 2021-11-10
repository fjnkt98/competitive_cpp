#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

int main() {
  int64_t H, W;
  std::cin >> H >> W;
  std::vector<std::string> grid(H);
  for (int64_t i = 0; i < H; i++) {
    std::cin >> grid.at(i);
  }

  int64_t white_cells = 0;
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (grid.at(i).at(j) == '.') {
        white_cells++;
      }
    }
  }

  std::vector<std::vector<int64_t>> distance(H, std::vector<int64_t>(W, -1));
  distance.at(0).at(0) = 0;
  std::queue<std::pair<int64_t, int64_t>> candidate;
  candidate.push(std::make_pair(0, 0));

  std::vector<int64_t> dr = {1, 0, -1, 0};
  std::vector<int64_t> dc = {0, 1, 0, -1};

  while (!candidate.empty()) {
    auto node = candidate.front();
    candidate.pop();

    for (int64_t i = 0; i < 4; i++) {
      int64_t next_row = node.first + dr.at(i);
      int64_t next_col = node.second + dc.at(i);

      if (next_row >= 0 && next_row < H && next_col >= 0 && next_col < W) {
        if (grid.at(next_row).at(next_col) == '.' && distance.at(next_row).at(next_col) == -1) {
          distance.at(next_row).at(next_col) = distance.at(node.first).at(node.second) + 1;
          candidate.push(std::make_pair(next_row, next_col));
        }
      }
    }
  }

  if (distance.at(H - 1).at(W - 1) == -1) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << white_cells - distance.at(H - 1).at(W - 1) - 1 << std::endl;
  }

  return 0;
}
