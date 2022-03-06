#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::sort(S.begin(), S.end());

  std::cout << S << std::endl;

  return 0;
}
