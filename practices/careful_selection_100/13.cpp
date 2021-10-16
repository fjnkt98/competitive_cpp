/*
 * https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t solve(int64_t bit, int64_t R, int64_t C, std::vector<std::vector<int64_t>> biscket) {
  for (int64_t i = 0; i < R; i++) {
    if (bit & (1 << i)) {
      for (int64_t j = 0; j < C; j++) {
        biscket.at(i).at(j) = 1 - biscket.at(i).at(j);
      }
    }
  }

  for (int64_t j = 0; j < C; j++) {
    int64_t count_fliped = 0;
    int64_t count_nonfliped = 0;
    for (int64_t i = 0; i < R; i++) {
      if (biscket.at(i).at(j) == 0) count_nonfliped++;
      if (biscket.at(i).at(j) == 1) count_fliped++;
    }

    if (count_fliped > count_nonfliped) {
      for (int64_t i = 0; i < R; i++) {
        biscket.at(i).at(j) = 1 - biscket.at(i).at(j);
      }
    }
  }

  int64_t count = 0;
  for (int64_t i = 0; i < R; i++) {
    for (int64_t j = 0; j < C; j++) {
      if (biscket.at(i).at(j) == 0) {
        count++;
      }
    }
  }

  return count;
}

int main() {
  int64_t R, C;
  std::cin >> R >> C;
  std::vector<std::vector<int64_t>> biscket(R, std::vector<int64_t>(C));
  for (int64_t i = 0; i < R; i++) {
    for (int64_t j = 0; j < C; j++) {
      std::cin >> biscket.at(i).at(j);
    }
  }

  int64_t answer = 0;
  for (int64_t bit = 0; bit < (1 << R); bit++) {
    answer = std::max(answer, solve(bit, R, C, biscket));
  }

  std::cout << answer << std::endl;

  return 0;
}
