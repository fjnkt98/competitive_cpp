#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void dfs(int64_t x, int64_t y, std::vector<std::string>& lake) {
  lake.at(x).at(y) = '.';

  for (int64_t dx = -1; dx <= 1; dx++) {
    for (int64_t dy = -1; dy <= 1; dy++) {
      if (0 <= x + dx && x + dx < static_cast<int64_t>(lake.size()) &&
          0 <= y + dy && y + dy < static_cast<int64_t>(lake.at(0).size())) {
        if (lake.at(x + dx).at(y + dy) == 'W') {
          dfs(x + dx, y + dy, lake);
        }
      }
    }
  }
}

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::string> lake(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> lake.at(i);
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < M; j++) {
      if (lake.at(i).at(j) == 'W') {
        dfs(i, j, lake);
        count++;
      }
    }
  }

  std::cout << count << std::endl;

  return 0;
}
