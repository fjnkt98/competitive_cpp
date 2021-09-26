#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, C;
  std::cin >> A >> B >> C;

  if (C == 0) {
    if (A <= B) {
      std::cout << "Aoki" << std::endl;
    } else {
      std::cout << "Takahashi" << std::endl;
    }
  } else {
    if (A >= B) {
      std::cout << "Takahashi" << std::endl;
    } else {
      std::cout << "Aoki" << std::endl;
    }
  }

  return 0;
}
