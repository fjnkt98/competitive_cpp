#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t X, Y, Z;
  std::cin >> X >> Y >> Z;

  int64_t answer = 0;
  X -= Z;
  while (X - (Y + Z) >= 0) {
    X -= (Y + Z);
    answer++;
  }

  std::cout << answer << std::endl;

  return 0;
}
