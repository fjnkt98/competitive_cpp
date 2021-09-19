#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<std::string> S(3);
  for (int64_t i = 0; i < 3; i++) {
    std::cin >> S.at(i);
  }
  std::string T;
  std::cin >> T;

  std::string answer;
  for (auto& t : T) {
    answer += S.at(t - '1');
  }

  std::cout << answer << std::endl;

  return 0;
}
