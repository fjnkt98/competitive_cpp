#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  int64_t answer = 1LL << 60;
  for (char c = 'a'; c <= 'z'; c++) {
    std::string T = S;

    int64_t count = 0;
    while (std::count(T.begin(), T.end(), c) != T.size()) {
      std::string U(T.size() - 1, ' ');
      for (int64_t i = 0; i < U.size(); i++) {
        if (T.at(i) == c || T.at(i + 1) == c) {
          U.at(i) = c;
        } else {
          U.at(i) = T.at(i);
        }
      }

      T = U;
      count++;
    }

    answer = std::min(answer, count);
  }

  std::cout << answer << std::endl;

  return 0;
}