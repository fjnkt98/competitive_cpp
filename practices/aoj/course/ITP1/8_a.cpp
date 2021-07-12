#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
  std::string str;
  while (true) {
    char ch;
    std::scanf("%c", &ch);
    if (ch == '\n') {
      break;
    } else {
      str.push_back(ch);
    }
  }

  std::string answer;
  for (auto s : str) {
    if (std::isalpha(s)) {
      if (std::islower(s)) {
        answer.push_back(std::toupper(s));
      } else {
        answer.push_back(std::tolower(s));
      }
    } else {
      answer.push_back(s);
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
