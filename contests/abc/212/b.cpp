#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  int64_t A = std::stoi(S);

  if (A % 1111 == 0) {
    std::cout << "Weak" << std::endl;
  } else {
    int64_t count = 0;
    for (int64_t i = 0; i < 3; i++) {
      if (S.at(i) != '9') {
        if (S.at(i) + 1 == S.at(i + 1)) {
          count++;
        }
      } else {
        if (S.at(i + 1) == '0') {
          count++;
        }
      }
    }

    if (count == 3) {
      std::cout << "Weak" << std::endl;
    } else {
      std::cout << "Strong" << std::endl;
    }
  }

  return 0;
}
