#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string S;
  std::cin >> S;
  int64_t K;
  std::cin >> K;

  bool flag = true;
  for (int64_t i = 0; i < std::min(K, static_cast<int64_t>(S.size())); i++) {
    if (S.at(i) != '1') {
      flag = false;
    }
  }

  if (flag) {
    std::cout << '1' << std::endl;
  } else {
    char answer = 0;
    for (size_t i = 0; i < S.size(); i++) {
      if (S.at(i) != '1') {
        answer = S.at(i);
        break;
      }
    }

    std::cout << answer << std::endl;
  }

  return 0;
}