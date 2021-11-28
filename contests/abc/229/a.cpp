#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<std::string> S(2);
  std::cin >> S.at(0);
  std::cin >> S.at(1);

  std::vector<std::string> A = {"#.", ".#"};
  std::vector<std::string> B = {".#", "#."};

  if (S == A || S == B) {
    std::cout << "No" << std::endl;
  } else {
    std::cout << "Yes" << std::endl;
  }

  return 0;
}
