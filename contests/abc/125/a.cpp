#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, T;
  std::cin >> A >> B >> T;

  std::cout << (T / A) * B << std::endl;

  return 0;
}
