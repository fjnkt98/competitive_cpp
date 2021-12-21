#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <queue>

int main() {
  int64_t H, W;
  std::cin >> H >> W;
  std::vector<std::string> grid(H);
  for (int64_t i = 0; i < H; i++) {
    std::cin >> grid.at(i);
  }

  std::vector<std::vector<int64_t>> distance(H, std::vector<int64_t>(W, -1));
  distance.at(0).at(0) = 1;
  std::queue<std::pair<int64_t, int64_t>> candidate;
  candidate.push(std::make_pair(0, 0));

  while (!candidate.empty()) {
    auto node = candidate.front();
    candidate.pop();

    int64_t r = node.first;
    int64_t c = node.second;

    std::array<int64_t, 2> dr = {0, 1};
    std::array<int64_t, 2> dc = {1, 0};

    for (int64_t i = 0; i < 2; i++) {
      int64_t next_row = r + dr.at(i);
      int64_t next_col = c + dc.at(i);

      if (next_row < H && next_col < W
          && grid.at(next_row).at(next_col) == '.'
          && distance.at(next_row).at(next_col) == -1)
      {
        distance.at(next_row).at(next_col) = distance.at(r).at(c) + 1;
        candidate.push(std::make_pair(next_row, next_col));
      }
    }
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      answer = std::max(answer, distance.at(i).at(j));
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
