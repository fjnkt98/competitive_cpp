#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::string S;
  std::cin >> S;

  std::string slimes = "";
  char last_color = '?';
  for (int64_t i = 0; i < N; i++) {
    if (last_color != S.at(i)) {
      slimes.push_back(S.at(i));
      last_color = S.at(i);
    }
  }

  std::cout << slimes.size() << std::endl;

  return 0;
}
