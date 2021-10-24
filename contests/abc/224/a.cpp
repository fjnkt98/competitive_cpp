#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  if (S.size() == 2) {
    if (S == "er") {
      std::cout << "er" << std::endl;
    }
  } else {
    if (S.substr(S.size() - 2, 2) == "er") {
      std::cout << "er" << std::endl;
    } else if (S.substr(S.size() - 3, 3) == "ist"){
      std::cout << "ist" << std::endl;
    }
  }

  return 0;
}
