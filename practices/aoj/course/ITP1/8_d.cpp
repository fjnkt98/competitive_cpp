#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string s, p;
  std::cin >> s >> p;

  std::string str = s + s;
  if (str.find(p) != std::string::npos) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
