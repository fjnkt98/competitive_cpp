#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

int main() {
  int64_t R, C;
  std::cin >> R >> C;
  int64_t sr, sc, gr, gc;
  std::cin >> sr >> sc >> gr >> gc;
  sr--;
  sc--;
  gr--;
  gc--;
  std::vector<std::string> maze(R);
  for (int64_t i = 0; i < R; i++) {
    std::cin >> maze.at(i);
  }

  std::vector<std::vector<int64_t>> distance(R, std::vector<int64_t>(C, -1));
  distance.at(sr).at(sc) = 0;

  std::queue<std::pair<int64_t, int64_t>> candidate;
  candidate.push(std::make_pair(sr, sc));

  std::vector<int64_t> dr = {1, 0, -1, 0};
  std::vector<int64_t> dc = {0, 1, 0, -1};

  while (!candidate.empty()) {
    auto cell = candidate.front();
    candidate.pop();

    for (int64_t i = 0; i < 4; i++) {
      int64_t r = cell.first + dr.at(i);
      int64_t c = cell.second + dc.at(i);

      if (r >= 0 && r < R && c >= 0 && c < C
          && maze.at(r).at(c) == '.'
          && distance.at(r).at(c) == -1)
      {
        distance.at(r).at(c) = distance.at(cell.first).at(cell.second) + 1;
        candidate.push(std::make_pair(r, c));
      }
    }
  }

  std::cout << distance.at(gr).at(gc) << std::endl;

  return 0;
}
