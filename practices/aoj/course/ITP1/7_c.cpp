#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t r, c;
  std::cin >> r >> c;
  std::vector<std::vector<int64_t>> table(r, std::vector<int64_t>(c));
  for (int64_t i = 0; i < r; i++) {
    for (int64_t j = 0; j < c; j++) {
      std::cin >> table.at(i).at(j);
    }
  }

  for (int64_t i = 0; i < r; i++) {
    int64_t row_sum = 0;
    for (int64_t j = 0; j < c; j++) {
      row_sum += table.at(i).at(j);
    }
    table.at(i).push_back(row_sum);
  }
  std::vector<int64_t> bottom_row(c + 1);
  for (int64_t i = 0; i < r; i++) {
    for (int64_t j = 0; j < c + 1; j++) {
      bottom_row.at(j) += table.at(i).at(j);
    }
  }
  table.push_back(bottom_row);

  for (int64_t i = 0; i < r + 1; i++) {
    for (int64_t j = 0; j < c + 1; j++) {
      std::cout << table.at(i).at(j);
      if (j != c) {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
