#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cctype>
#include <cstdio>

int main() {
  char ch;
  std::string str;
  std::vector<int64_t> answer(26, 0);
  // While-space will be ignored.
  while (std::cin >> ch) {
    str.push_back(ch);
  }

  for (auto s : str) {
    if (std::isalpha(s)) {
      if (std::islower(s)) {
        answer.at(s - 'a')++;
      } else {
        answer.at(std::tolower(s) - 'a')++;
      }
    }
  }

  for (int64_t i = 0; i < answer.size(); i++) {
    std::cout << static_cast<char>(i + 'a') << " : " << answer.at(i) << std::endl;
  }

  return 0;
}
