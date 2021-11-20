#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t S, T, X;
  std::cin >> S >> T >> X;

  if (S > T) {
    if (T <= X && X < S) {
      std::cout << "No" << std::endl;
    } else {
      std::cout << "Yes" << std::endl;
    }
  } else {
    if (S <= X && X < T) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }

  return 0;
}
