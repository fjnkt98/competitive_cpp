#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::string S, T;
  std::cin >> N >> S >> T;

  std::string answer = "";
  for (int64_t i = 0; i < N; i++) {
    answer.push_back(S.at(i));
    answer.push_back(T.at(i));
  }

  std::cout << answer << std::endl;

  return 0;
}
