#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  const int64_t width = 1000;
  const int64_t height = 1000;
  int64_t N;
  std::cin >> N;

  std::vector<std::pair<int64_t, int64_t>> l(N);
  std::vector<std::pair<int64_t, int64_t>> r(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t lx, ly, rx, ry;
    std::cin >> lx >> ly >> rx >> ry;
    l.at(i) = std::make_pair(lx, ly);
    r.at(i) = std::make_pair(rx, ry);
  }

  std::vector<std::vector<int64_t>> overlap(height + 1, std::vector<int64_t>(width + 1, 0));

  for (int64_t i = 0; i < N; i++) {
    int64_t lx = l.at(i).first;
    int64_t ly = l.at(i).second;
    int64_t rx = r.at(i).first;
    int64_t ry = r.at(i).second;

    overlap.at(lx).at(ly)++;
    overlap.at(rx).at(ry)++;
    overlap.at(lx).at(ry)--;
    overlap.at(rx).at(ly)--;
  }

  for (int64_t y = 0; y <= height; y++) {
    for (int64_t x = 0; x < width; x++) {
      overlap.at(x + 1).at(y) += overlap.at(x).at(y);
    }
  }

  for (int64_t x = 0; x <= width; x++) {
    for (int64_t y = 0; y < height; y++) {
      overlap.at(x).at(y + 1) += overlap.at(x).at(y);
    }
  }

  std::vector<int64_t> area(N + 1);
  for (int64_t y = 0; y <= height; y++) {
    for (int64_t x = 0; x <= width; x++) {
      area.at(overlap.at(x).at(y))++;
    }
  }

  for (int64_t i = 1; i <= N; i++) {
    if (i != 1) std::cout << std::endl;
    std::cout << area.at(i);
  }
  std::cout << std::endl;

  return 0;
}
