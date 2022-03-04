#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::string> grid(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> grid.at(i);
  }

  bool ok = false;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < N; j++) {
      std::pair<int64_t, int64_t> horizontal_count = {0, 0};
      for (int64_t r = 0; r < 6; r++) {
        if (i + r >= N) break;
        if (grid.at(i + r).at(j) == '#')
          horizontal_count.first++;
        else
          horizontal_count.second++;
      }

      std::pair<int64_t, int64_t> vertical_count = {0, 0};
      for (int64_t c = 0; c < 6; c++) {
        if (j + c >= N) break;
        if (grid.at(i).at(j + c) == '#')
          vertical_count.first++;
        else
          vertical_count.second++;
      }

      std::pair<int64_t, int64_t> diagonal_count = {0, 0};
      for (int64_t k = 0; k < 6; k++) {
        if (i + k >= N || j + k >= N) break;
        if (grid.at(i + k).at(j + k) == '#')
          diagonal_count.first++;
        else
          diagonal_count.second++;
      }

      std::pair<int64_t, int64_t> inverse_diagonal_count = {0, 0};
      for (int64_t k = 0; k < 6; k++) {
        if (i + k >= N || j - k < 0) break;
        if (grid.at(i + k).at(j - k) == '#')
          inverse_diagonal_count.first++;
        else
          inverse_diagonal_count.second++;
      }

      ok = ok || (horizontal_count.first + horizontal_count.second == 6 &&
                  horizontal_count.first >= 4);
      ok = ok || (vertical_count.first + vertical_count.second == 6 &&
                  vertical_count.first >= 4);
      ok = ok || (diagonal_count.first + diagonal_count.second == 6 &&
                  diagonal_count.first >= 4);
      ok = ok ||
           (inverse_diagonal_count.first + inverse_diagonal_count.second == 6 &&
            inverse_diagonal_count.first >= 4);
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
