#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  if (A < 10 && B < 10) {
    std::cout << A * B << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }

  return 0;
}
