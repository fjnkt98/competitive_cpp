#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>

void dfs(std::vector<std::string>& grid, int64_t& step_count,
         int64_t r, int64_t c)
{
  int64_t H = grid.size();
  int64_t W = grid.at(0).length();

  std::array<int64_t, 4> dr = {1, 0, -1, 0};
  std::array<int64_t, 4> dc = {0, 1, 0, -1};

  grid.at(r).at(c) = '.';
  step_count++;

  for (int64_t i = 0; i < 4; i++) {
    int64_t next_r = r + dr.at(i);
    int64_t next_c = c + dc.at(i);

    if (next_r >= 0 && next_r < H && next_c >= 0 && next_c < W) {
      if (grid.at(next_r).at(next_c) == '#') {
        dfs(grid, step_count, next_r, next_c);
      }
    }
  }
}

int main() {
  int64_t H, W;
  std::cin >> H >> W;
  std::vector<std::string> grid(H);
  for (int64_t i = 0; i < H; i++) {
    std::cin >> grid.at(i);
  }

  bool ok = true;
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (grid.at(i).at(j) == '#') {
        int64_t step_count = 0;
        dfs(grid, step_count, i, j);

        if (step_count == 1) {
          ok = false;
        }
      }
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
