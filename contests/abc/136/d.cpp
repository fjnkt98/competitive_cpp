#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::vector<std::pair<int64_t, int64_t>> token;
  token.push_back(std::make_pair(-2, -1));
  for (size_t i = 0; i < S.size() - 1; i++) {
    if (S.at(i) == 'R' && S.at(i + 1) == 'L') {
      token.push_back(std::make_pair(i, i + 1));
    }
  }
  token.push_back(std::make_pair(S.size(), S.size() + 1));

  std::vector<int64_t> answer(S.size(), 0);
  for (size_t i = 1; i < token.size() - 1; i++) {
    answer.at(token.at(i).first) = 1;
    answer.at(token.at(i).second) = 1;

    for (int64_t j = token.at(i - 1).first + 2; j < token.at(i).first; j++) {
      if (S.at(j) == 'R') {
        if ((token.at(i).first - j) % 2 == 0) {
          answer.at(token.at(i).first)++;
        }

        if ((token.at(i).second - j) % 2 == 0) {
          answer.at(token.at(i).second)++;
        }
      }
    }
    for (int64_t j = token.at(i).first + 2; j < token.at(i + 1).first; j++) {
      if (S.at(j) == 'L') {
        if ((j - token.at(i).first) % 2 == 0) {
          answer.at(token.at(i).first)++;
        }

        if ((j - token.at(i).second) % 2 == 0) {
          answer.at(token.at(i).second)++;
        }
      }
    }
  }

  /* for (auto t : token) { */
  /*   std::cout << t.first << " " << t.second << std::endl; */
  /* } */

  for (size_t i = 0; i < S.size(); i++) {
    if (i) std::cout << " ";
    std::cout << answer.at(i);
  }
  std::cout << std::endl;

  return 0;
}
