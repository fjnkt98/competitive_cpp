/*
 * https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_d
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t dfs(std::vector<std::vector<int64_t>>& grid,
         int64_t r, int64_t c)
{
  int64_t N = static_cast<int64_t>(grid.size());
  int64_t M = static_cast<int64_t>(grid.at(0).size());

  std::vector<int64_t> dr = {1, 0, -1, 0};
  std::vector<int64_t> dc = {0, 1, 0, -1};

  grid.at(r).at(c) = 0;

  int64_t max_step = 1;
  for (int64_t i = 0; i < 4; i++) {
    int64_t next_r = r + dr.at(i);
    int64_t next_c = c + dc.at(i);
    if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M) {
      if (grid.at(next_r).at(next_c) == 1) {
        max_step = std::max(max_step, dfs(grid, next_r, next_c) + 1);
      }
    }
  }
  grid.at(r).at(c) = 1;

  return max_step;
}


int main() {
  int64_t M, N;
  std::cin >> M >> N;
  std::vector<std::vector<int64_t>> grid(N, std::vector<int64_t>(M));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < M; j++) {
      std::cin >> grid.at(i).at(j);
    }
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < M; j++) {
      if (grid.at(i).at(j) == 1) {
        answer = std::max(answer, dfs(grid, i, j));
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
