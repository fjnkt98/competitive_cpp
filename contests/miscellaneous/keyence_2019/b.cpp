#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  if (S == "keyence") {
    std::cout << "YES" << std::endl;
    return 0;
  }

  for (size_t i = 0; i < S.size(); i++) {
    for (size_t j = 1; j < S.size(); j++) {
      std::string T;

      for (size_t k = 0; k < S.size(); k++) {
        if (k >= i && k < i + j) continue;
        T.push_back(S.at(k));
      }

      if (T == "keyence") {
        std::cout << "YES" << std::endl;
        return 0;
      }
    }
  }

  std::cout << "NO" << std::endl;
  return 0;
}
