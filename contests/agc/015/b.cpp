#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  int64_t N = static_cast<int64_t>(S.size());

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    if (S.at(i) == 'U') {
      answer += (N - i - 1) + 2 * i;
    } else {
      answer += 2 * (N - i - 1) + i;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}