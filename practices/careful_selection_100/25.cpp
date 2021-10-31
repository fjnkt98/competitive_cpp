/*
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

void dfs(std::vector<std::vector<int64_t>>& grid,
         std::vector<std::vector<bool>>& explored,
         int64_t i,
         int64_t j)
{
  int64_t H = static_cast<int64_t>(grid.size());
  int64_t W = static_cast<int64_t>(grid.at(0).size());
  std::vector<int64_t> dr = {1, 1, 1, 0, 0, -1, -1, -1};
  std::vector<int64_t> dc = {1, 0, -1, 1, -1, 1, 0, -1};

  for (int64_t k = 0; k < 8; k++) {
    for (int64_t l = 0; l < 8; l++) {
      int64_t r = i + dr.at(k);
      int64_t c = j + dc.at(l);
      if (r >= 0 && r < H && c >= 0 && c < W && grid.at(r).at(c) == 1) {
        if (explored.at(r).at(c)) continue;
        explored.at(r).at(c) = true;
        dfs(grid, explored, r, c);
      }
    }
  }
}

int main() {
  std::vector<int64_t> answer;

  while (true) {
    int64_t W, H;
    std::cin >> W >> H;
    if (W == 0 && H == 0) break;

    std::vector<std::vector<int64_t>> grid(H, std::vector<int64_t>(W));
    for (int64_t i = 0; i < H; i++) {
      for (int64_t j = 0; j < W; j++) {
        std::cin >> grid.at(i).at(j);
      }
    }

    std::vector<std::vector<bool>> explored(H, std::vector<bool>(W, false));

    int64_t count = 0;
    for (int64_t i = 0; i < H; i++) {
      for (int64_t j = 0; j < W; j++) {
        if (grid.at(i).at(j) == 0 || explored.at(i).at(j)) continue;
        explored.at(i).at(j) = true;
        dfs(grid, explored, i, j);
        count++;
      }
    }
    answer.push_back(count);
  }

  for (auto a : answer) {
    std::cout << a << std::endl;
  }

  return 0;
}

