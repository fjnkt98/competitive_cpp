#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string S;
  std::cin >> S;

  std::cout << S.at(S.size() / 2) << std::endl;

  return 0;
}