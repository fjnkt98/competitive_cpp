#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  char C1, C2, C3;
  std::cin >> C1 >> C2 >> C3;

  if (C1 == C2 && C2 == C3) {
    std::cout << "Won" << std::endl;
  } else {
    std::cout << "Lost" << std::endl;
  }

  return 0;
}
