#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string a, b;
  std::cin >> a >> b;

  int64_t ab = std::stol(a + b);
  for (int64_t i = 0; i * i < 100000; i++) {
    if (i * i ==  ab) {
      std::cout << "Yes" << std::endl;
      return 0;
    }
  }
  std::cout << "No" << std::endl;

  return 0;
}
