#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::string month = S.substr(5, 2);

  int64_t m = std::stoi(month);

  if (m <= 4) {
    std::cout << "Heisei" << std::endl;
  } else {
    std::cout << "TBD" << std::endl;
  }

  return 0;
}
