#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t H, W;
  std::cin >> H >> W;
  std::vector<std::string> S(H);
  for (int64_t i = 0; i < H; i++) {
    std::cin >> S.at(i);
  }

  std::vector<std::vector<int64_t>> horizontal_obstacle(H);
  std::vector<std::vector<int64_t>> vertical_obstacle(W);

  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (S.at(i).at(j) == '#') {
        horizontal_obstacle.at(i).push_back(j);
        vertical_obstacle.at(j).push_back(i);
      }
    }
  }

  for (auto& h : horizontal_obstacle) {
    h.push_back(-1);
    h.push_back(W);
    std::sort(h.begin(), h.end());
  }
  for (auto& v : vertical_obstacle) {
    v.push_back(-1);
    v.push_back(H);
    std::sort(v.begin(), v.end());
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (S.at(i).at(j) == '.') {
        auto iter = std::lower_bound(horizontal_obstacle.at(i).begin(), horizontal_obstacle.at(i).end(), j);
        int64_t right = *iter - j;
        int64_t left = j - *(std::prev(iter));

        iter = std::lower_bound(vertical_obstacle.at(j).begin(), vertical_obstacle.at(j).end(), i);
        int64_t bottom = *iter - i;
        int64_t above = i - *(std::prev(iter));

        answer = std::max(answer, right + left + bottom + above - 3);
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
