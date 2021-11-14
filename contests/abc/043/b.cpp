#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::string answer = "";
  for (char c : S) {
    if (c == '0' || c == '1') {
      answer.push_back(c);
    }
    if (c == 'B') {
      if (answer.empty()) continue;
      else answer.pop_back();
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
