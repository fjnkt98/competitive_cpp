#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::string T = S;
  for (size_t i = 0; i < S.size(); i++) {
    if (S.at(i) == ',') {
      T.at(i) = ' ';
    } else {
      T.at(i) = S.at(i);
    }
  }

  std::cout << T << std::endl;

  return 0;
}
