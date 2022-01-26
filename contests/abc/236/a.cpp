#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string S;
  std::cin >> S;
  int64_t a, b;
  std::cin >> a >> b;

  std::swap(S.at(a - 1), S.at( b -1 ));

  std::cout << S << std::endl;

  return 0;
}
