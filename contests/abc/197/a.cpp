#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::cout << S.at(1) << S.at(2) << S.at(0) << std::endl;

  return 0;
}
