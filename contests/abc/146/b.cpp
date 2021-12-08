#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::string S;
  std::cin >> S;

  for (size_t i = 0; i < S.size(); i++) {
    char c = S.at(i) + N;

    if (c - 'A' >= 26) {
      c -= 26;
    }

    S.at(i) = c;
  }

  std::cout << S << std::endl;

  return 0;
}
