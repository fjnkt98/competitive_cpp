#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  int64_t answer = 0;
  char current_color = S.at(0);

  for (size_t i = 1; i < S.size(); i++) {
    if (S.at(i) == current_color) continue;

    answer++;
    current_color = S.at(i);
  }

  std::cout << answer << std::endl;


  return 0;
}
