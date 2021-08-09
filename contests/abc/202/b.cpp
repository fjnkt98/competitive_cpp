#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::reverse(S.begin(), S.end());

  for (char& s : S) {
    char replace_character = s;
    if (s == '6') {
      replace_character = '9';
    }
    if (s == '9') {
      replace_character = '6';
    }
    s = replace_character;
  }

  for (char& s : S) {
    std::cout << s;
  }
  std::cout << std::endl;
  return 0;
}
