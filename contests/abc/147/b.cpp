#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string S;
  std::cin >> S;

  int64_t N = static_cast<int64_t>(S.size());
  std::string T = S;
  std::reverse(T.begin(), T.end());

  int64_t answer = 0;
  for (int64_t i = 0; i < N / 2; i++) {
    if (S.at(i) != T.at(i)) {
      answer++;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
