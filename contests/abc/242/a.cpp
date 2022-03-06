#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, C, X;
  std::cin >> A >> B >> C >> X;

  if (X <= A) {
    std::cout << 1 << std::endl;
  } else if (X <= B) {
    std::cout << static_cast<double>(C) / (B - A) << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}
