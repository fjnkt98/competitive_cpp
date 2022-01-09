#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  if (A % 3 == 0) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}