/*
 * https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e
 */
#include <cctype>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <array>

int main() {
  int64_t H, W, N;
  std::cin >> H >> W >> N;
  std::vector<std::string> grid(H);
  for (int64_t i = 0; i < H; i++) {
    std::cin >> grid.at(i);
  }

  std::vector<std::pair<int64_t, int64_t>> place_of_cheeses(N + 1);
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (std::isdigit(grid.at(i).at(j))) {
        place_of_cheeses.at(static_cast<int64_t>(grid.at(i).at(j) - '0')) = std::make_pair(i, j);
      } else if (grid.at(i).at(j) == 'S') {
        place_of_cheeses.at(0) = std::make_pair(i, j);
      }
    }
  }

  const std::array<int64_t, 4> dr = {1, 0, -1, 0};
  const std::array<int64_t, 4> dc = {0, 1, 0, -1};

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    int64_t start_row = place_of_cheeses.at(i).first;
    int64_t start_column = place_of_cheeses.at(i).second;

    std::queue<std::pair<int64_t, int64_t>> candidate;
    candidate.push(std::make_pair(start_row, start_column));
    std::vector<std::vector<int64_t>> distance(H, std::vector<int64_t>(W, -1));
    distance.at(start_row).at(start_column) = 0;

    while (!candidate.empty()) {
      auto node = candidate.front();
      candidate.pop();

      int64_t row = node.first;
      int64_t column = node.second;

      for (int64_t j = 0; j < 4; j++) {
        int64_t next_row = row + dr.at(j);
        int64_t next_column = column + dc.at(j);

        if (next_row >= 0 && next_row < H && next_column >= 0 && next_column < W
            && grid.at(next_row).at(next_column) != 'X'
            && distance.at(next_row).at(next_column) == -1)
        {
          distance.at(next_row).at(next_column) = distance.at(row).at(column) + 1;
          candidate.push(std::make_pair(next_row, next_column));
        }
      }
    }

    answer += distance.at(place_of_cheeses.at(i + 1).first).at(place_of_cheeses.at(i + 1).second);
  }

  std::cout << answer << std::endl;

  return 0;
}
