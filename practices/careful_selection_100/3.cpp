/*
 * https://atcoder.jp/contests/abc122/tasks/abc122_b
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  int64_t longest_length = 0;
  for (int64_t i = 0; i < static_cast<int64_t>(S.size()); i++) {
    if (!(S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'G' || S.at(i) == 'T')) continue;

    for (int64_t j = 0; i + j < static_cast<int64_t>(S.size()); j++) {
      if (S.at(i + j) == 'A' || S.at(i + j) == 'C' || S.at(i + j) == 'G' || S.at(i + j) == 'T') {
        longest_length = std::max(longest_length, j + 1);
      } else {
        break;
      }
    }
  }

  std::cout << longest_length << std::endl;

  return 0;
}
