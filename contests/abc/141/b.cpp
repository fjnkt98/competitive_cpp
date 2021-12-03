#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  bool ok = true;
  for (size_t i = 0; i < S.size(); i++) {
    if (i % 2 == 0) {
      if (S.at(i) != 'R' && S.at(i) != 'U' && S.at(i) != 'D') {
        ok = false;
      }
    } else {
      if (S.at(i) != 'L' && S.at(i) != 'U' && S.at(i) != 'D') {
        ok = false;
      }
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
