#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t X, Y;
  std::cin >> X >> Y;

  if (Y <= X) {
    std::cout << 0 << std::endl;
  } else {
    int64_t diff = Y - X;
    if (diff % 10 == 0) {
      std::cout << diff / 10 << std::endl;
    } else {
      std::cout << diff / 10 + 1 << std::endl;
    }
  }

  return 0;
}
