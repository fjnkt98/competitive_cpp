#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
  std::string S;
  std::cin >> S;

  bool unreadable = true;
  for (size_t i = 0; i < S.size(); i++) {
    if (i % 2 == 0) {
      if (!std::islower(S.at(i))) {
        unreadable = false;
      }
    } else {
      if (!std::isupper(S.at(i))) {
        unreadable = false;
      }
    }
  }

  if (unreadable) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
