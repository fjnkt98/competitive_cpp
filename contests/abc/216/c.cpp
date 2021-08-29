#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::string answer;
  while (N > 0) {
    if (N % 2 == 0) {
      N /= 2;
      answer.push_back('B');
    } else {
      N -= 1;
      answer.push_back('A');
    }
  }

  std::reverse(answer.begin(), answer.end());
  std::cout << answer << std::endl;

  return 0;
}
