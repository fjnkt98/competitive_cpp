#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <deque>

int main() {
  int64_t N;
  std::cin >> N;
  int64_t Ax, Ay, Bx, By;
  std::cin >> Ax >> Ay >> Bx >> By;
  Ax--;
  Ay--;
  Bx--;
  By--;

  std::vector<std::string> grid(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> grid.at(i);
  }

  std::vector<std::vector<int64_t>> distance(
      N, std::vector<int64_t>(N, 1LL << 60));
  distance.at(Ax).at(Ay) = 0;

  std::vector<int64_t> dx = {1, 1, -1, -1};
  std::vector<int64_t> dy = {1, -1, 1, -1};

  std::deque<std::tuple<int64_t, int64_t, int64_t, int64_t>> candidate;
  for (int64_t i = 0; i < 4; i++) {
    int64_t nx = Ax + dx.at(i);
    int64_t ny = Ay + dy.at(i);

    if (0 <= nx && nx < N && 0 <= ny && ny < N and grid.at(nx).at(ny) == '.') {
      distance.at(nx).at(ny) = 1;
      candidate.push_back(std::make_tuple(nx, ny, i, 1));
    }
  }

  while (!candidate.empty()) {
    auto [x, y, d, c] = candidate.front();
    candidate.pop_front();

    if (c > distance.at(x).at(y)) continue;

    for (int64_t i = 0; i < 4; i++) {
      int64_t nx = x + dx.at(i);
      int64_t ny = y + dy.at(i);

      if (0 <= nx && nx < N && 0 <= ny && ny < N && grid.at(nx).at(ny) == '.') {
        if (d == i) {
          if (c <= distance.at(nx).at(ny)) {
            distance.at(nx).at(ny) = distance.at(x).at(y);
            candidate.push_front(std::make_tuple(nx, ny, i, c));
          }
        } else {
          if (c < distance.at(nx).at(ny)) {
            distance.at(nx).at(ny) = distance.at(x).at(y) + 1;
            candidate.push_back(std::make_tuple(nx, ny, i, c + 1));
          }
        }
      }
    }
  }

  if (distance.at(Bx).at(By) == 1LL << 60) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << distance.at(Bx).at(By) << std::endl;
  }

  return 0;
}