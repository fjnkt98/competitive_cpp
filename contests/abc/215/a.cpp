#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  if (S == "Hello,World!") {
    std::cout << "AC" << std::endl;
  } else {
    std::cout << "WA" << std::endl;
  }

  return 0;
}
