#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string A, B, S;
  std::cin >> A >> B >> S;

  bool ok = true;
  for (size_t i = 0; i < S.size(); i++) {
    if (i == std::stoll(A)) {
      if (S.at(i) != '-') {
        ok = false;
      }
    } else {
      if (S.at(i) < '0' || S.at(i) > '9') {
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
