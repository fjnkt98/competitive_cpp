#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string X;
  std::cin >> X;

  for (size_t i = 0; i < X.size(); i++) {
    if (X.at(i) == '.') break;

    std::cout << X.at(i);
  }
  std::cout << std::endl;

  return 0;
}
