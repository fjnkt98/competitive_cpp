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
    std::string S = T.substr(i, P.size());

    if (S == P) {
      std::cout << i << std::endl;
    }
  }

  return 0;
}
