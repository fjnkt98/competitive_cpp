#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::vector<std::string> divide = {"dream", "dreamer", "erase", "eraser"};

  std::reverse(S.begin(), S.end());
  for (int64_t i = 0; i < divide.size(); i++) {
    std::reverse(divide.at(i).begin(), divide.at(i).end());
  }

  bool satisfied = true;
  for (int64_t i = 0; i < S.size();) {
    bool dividable = false;
    for (int64_t j = 0; j < 4; j++) {
      if (S.substr(i, divide.at(j).size()) == divide.at(j)) {
        dividable = true;
        i += divide.at(j).size();
      }
    }

    if (!dividable) {
      satisfied = false;
      break;
    }
  }

  if (satisfied) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
