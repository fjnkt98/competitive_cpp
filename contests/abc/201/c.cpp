#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  int64_t answer = 0;
  for (int64_t i = 0; i <= 9999 ; i++) {
    std::string i_str = std::to_string(i);
    if (i_str.size() != 4) {
      std::string prefix(4 - i_str.size(), '0');
      i_str = prefix + i_str;
    }

    std::vector<uint8_t> digit_exist(10, 0);
    for (char c : i_str) {
      digit_exist.at(c - '0') = 1;
    }

    bool satisfied = true;
    for (int64_t j = 0; j < 10; j++) {
      if (S.at(j) == 'o' && digit_exist.at(j) == 0) satisfied = false;
      if (S.at(j) == 'x' && digit_exist.at(j) == 1) satisfied = false;
    }

    if (satisfied) answer++;
  }

  std::cout << answer << std::endl;

  return 0;
}
