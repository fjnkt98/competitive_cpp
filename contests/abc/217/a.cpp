#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S, T;
  std::cin >> S >> T;

  if (S < T) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
