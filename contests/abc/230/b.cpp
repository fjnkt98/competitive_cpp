#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::string T = "";
  for (int64_t i = 0; i < 20; i++) {
    T += "oxx";
  }

  bool ok = false;
  for (size_t i = 0; i < T.size() - S.size() + 1; i++) {
    if (S == T.substr(i, S.size())) {
      ok = true;
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }


  return 0;
}
