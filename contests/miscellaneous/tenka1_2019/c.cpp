#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::string S;
  std::cin >> S;

  int64_t black = 0;
  int64_t white = std::count(S.begin(), S.end(), '.');
  int64_t answer = white;

  for (int64_t i = 0; i < N; i++) {
    if (S.at(i) == '.') {
      black--;
    } else {
      white++;
    }

    answer = std::min(answer, white + black);
  }

  std::cout << answer << std::endl;

  return 0;
}