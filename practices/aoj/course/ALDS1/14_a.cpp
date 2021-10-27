#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string T, P;
  std::cin >> T >> P;

  if (T.size() < P.size()) {
    return 0;
  }

  for (size_t i = 0; i < T.size() - P.size() + 1; i++) {
    bool match = true;
    for (size_t j = 0; j < P.size(); j++) {
      if (T.at(i + j) != P.at(j)) {
        match = false;
      }
    }
    if (match) {
      std::cout << i << std::endl;
    }
  }

  return 0;
}
