#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string S;
  std::cin >> S;

  int64_t answer = 0;
  int64_t left = 0;
  int64_t right = static_cast<int64_t>(S.size()) - 1;

  while (right - left > 0) {
    if (S.at(left) == S.at(right)) {
      left++;
      right--;
    } else if (S.at(left) != 'x' && S.at(right) != 'x') {
      answer = -1;
      break;
    } else if (S.at(left) == 'x') {
      left++;
      answer++;
    } else {
      right--;
      answer++;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}