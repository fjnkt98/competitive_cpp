#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::cout << static_cast<int64_t>(S.at(0) - '0') * static_cast<int64_t>(S.at(2) - '0') << std::endl;

  return 0;
}
