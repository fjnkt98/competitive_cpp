#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S, T;
  std::cin >> S >> T;

  if (S == T) {
    std::cout << 0 << std::endl;
    return 0;
  }

  int64_t answer = -1;
  for (size_t i = 0; i < S.size(); i++) {
    S = S.back() + S;
    S.pop_back();
    if (S == T) {
      answer = static_cast<int64_t>(i) + 1;
      break;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
