#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t X;
  std::cin >> X;

  for (int64_t i = 1; i <= X; i++) {
    if ((i * (i + 1)) / 2 >= X) {
      std::cout << i << std::endl;
      break;
    }
  }

  return 0;
}
