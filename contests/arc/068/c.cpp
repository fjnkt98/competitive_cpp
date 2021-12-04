#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t X;
  std::cin >> X;

  int64_t residue = X % 11;
  int64_t answer = 2 * (X / 11);

  if (residue == 0) {
    std::cout << answer << std::endl;
  } else if (residue <= 6) {
    std::cout << answer + 1 << std::endl;
  } else {
    std::cout << answer + 2 << std::endl;
  }

  return 0;
}
