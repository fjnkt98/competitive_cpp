#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;

  std::string answer = "1";
  for (int64_t i = 0; i < N; i++) {
    answer.push_back('0');
  }

  std::cout << answer << std::endl;

  return 0;
}