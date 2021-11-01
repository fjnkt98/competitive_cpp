/*
 * https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_e
 */
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t W, H;
  std::cin >> W >> H;
  std::vector<std::vector<int32_t>> building(H + 2, std::vector<int32_t>(W + 2, 0));
  for (int64_t i = 1; i <= H; i++) {
    for (int64_t j = 1; j <= W; j++) {
      std::cin >> building.at(i).at(j);
    }
  }

  std::vector<std::vector<int64_t>> dr = {{-1, 0, 1, 1, 0, -1},
                                          {-1, 0, 1, 1, 0, -1}};

  std::vector<std::vector<int64_t>> dc = {{0, 1, 0, -1, -1, -1},
                                          {1, 1, 1, 0, -1, 0}};

  std::queue<std::pair<int64_t, int64_t>> candidate;
  candidate.push(std::make_pair(0, 0));
  std::vector<std::vector<bool>> explored(H + 2, std::vector<bool>(W + 2, false));
  explored.at(0).at(0) = true;
  int64_t answer = 0;
  while (!candidate.empty()) {
    auto node = candidate.front();
    candidate.pop();

    int64_t row = node.first;
    int64_t col = node.second;

    for (int64_t i = 0; i < 6; i++) {
      int64_t next_row = row + dr.at(row % 2).at(i);
      int64_t next_col = col + dc.at(row % 2).at(i);
      if (next_row >= 0 && next_row < H + 2 && next_col >= 0 && next_col < W + 2) {
        if (building.at(next_row).at(next_col) == 0 && explored.at(next_row).at(next_col) == false) {
          explored.at(next_row).at(next_col) = true;
          candidate.push(std::make_pair(next_row, next_col));
        } else if (building.at(next_row).at(next_col) == 1) {
          answer++;
        }
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
