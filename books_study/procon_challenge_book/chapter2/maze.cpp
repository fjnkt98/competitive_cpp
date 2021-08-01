#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::string> maze(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> maze.at(i);
  }

  std::pair<int64_t, int64_t> start;
  std::pair<int64_t, int64_t> goal;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < M; j++) {
      if (maze.at(i).at(j) == 'S') {
        start = std::make_pair(i, j);
      }
      if (maze.at(i).at(j) == 'G') {
        goal = std::make_pair(i, j);
      }
    }
  }

  std::vector<std::vector<int64_t>> distance(N, std::vector<int64_t>(M, -1));
  std::vector<int64_t> dx = {1, 0, -1, 0};
  std::vector<int64_t> dy = {0, 1, 0, -1};

  std::queue<std::pair<int64_t, int64_t>> candidate;
  candidate.push(start);
  distance.at(start.first).at(start.second) = 0;

  while (!candidate.empty()) {
    auto p = candidate.front();
    candidate.pop();

    if (p.first == goal.first && p.second == goal.second) {
      break;
    }


    for (int64_t i = 0; i < 4; i++) {
      int64_t x = p.first + dx.at(i);
      int64_t y = p.second + dy.at(i);

      if (0 <= x && x < N &&
          0 <= y && y < M &&
          maze.at(x).at(y) != '#' &&
          distance.at(x).at(y) == -1)
      {
        candidate.push(std::make_pair(x, y));
        distance.at(x).at(y) = distance.at(p.first).at(p.second) + 1;
      }
    }
  }

  std::cout << distance.at(goal.first).at(goal.second) << std::endl;

  return 0;
}
